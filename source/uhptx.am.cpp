

/**
 
 uhptx.am - Max Object implementing an Ultrahaptics Amplitude Modulation Emitter
 by Aditya Tirumala B, IDMIL, McGill University, 2017.
 
 **/



#include "ext.h"
#include "UltrahapticsAmplitudeModulation.hpp"


typedef struct _uhptx{
    
    t_object uh_obj;
    long proxy_inlet;
    void *proxy[4];
    int initialized;
    
    float x_coordinate[4];
    float y_coordinate[4];
    float height[4];
    float point_intensity[4];
    float frequency[4];
    int  nControlPoints;
    
    Ultrahaptics::Vector3 position[4];
}t_uhptx;


//**Prototypes**//
void *uhptx_new(t_symbol *s, long argc, t_atom *argv);
void uhptx_clear(t_uhptx *x);
void uhptx_assist(t_uhptx *x, void *b, long m, long a, char *s);

void uhptx_bang(t_uhptx *x);
void uhptx_initialize(t_uhptx *x);
void uhptx_test(t_uhptx *x);
void uhptx_update(t_uhptx *x);
void uhptx_stop(t_uhptx *x);
void uhptx_off(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);
void uhptx_reset(t_uhptx *x);

void uhptx_list(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);

void uhptx_pt1(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);
void uhptx_pt2(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);
void uhptx_pt3(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);
void uhptx_pt4(t_uhptx *x, t_symbol *s, long argc, t_atom *argv);

bool arg_check(t_uhptx *x, long val, int point_id);

//**************//

Ultrahaptics::UltrahapticsLibrary lib;
Ultrahaptics::AmplitudeModulation::Emitter emitter;
Ultrahaptics::ControlPoint controlPoints[4] = {Ultrahaptics::ControlPoint(0,0,0,0,0), Ultrahaptics::ControlPoint(0,0,0,0,0), Ultrahaptics::ControlPoint(0,0,0,0,0), Ultrahaptics::ControlPoint(0,0,0,0,0)};


static t_class *uhptx_class;

void ext_main(void *r){
    
    t_class *c;
    
    c = class_new("uhptx.am", (method)uhptx_new, (method)uhptx_clear, sizeof(t_uhptx), 0L, A_GIMME,0);
    class_addmethod(c, (method)uhptx_bang, "bang", 0);
    class_addmethod(c, (method)uhptx_initialize, "init", 0);
    class_addmethod(c, (method)uhptx_test, "test", 0);
    class_addmethod(c, (method)uhptx_reset, "reset",0);
//    class_addmethod(c, (method)uhptx_initialize, "initialize", 0);
    class_addmethod(c, (method)uhptx_off, "off", 0);
    class_addmethod(c, (method)uhptx_stop, "stop", 0);
    class_addmethod(c, (method)uhptx_list, "list", A_GIMME,0);
    class_addmethod(c, (method)uhptx_assist, "assist", A_CANT, 0);
    
    class_register(CLASS_BOX, c);
    uhptx_class = c;
    
}

/****** Initialization and Assistance Routines ******/
void *uhptx_new(t_symbol *s, long argc, t_atom *argv){
    
    t_uhptx *x = (t_uhptx *)object_alloc(uhptx_class);
    
    unsigned int deviceID;
    x->initialized = 0;
    x->nControlPoints = 4;
    
    if(lib.getDeviceCount()>=1){
        if(argc>0){
            deviceID = (unsigned int)atom_getlong(argv) - 1;
        }else{
            deviceID = 0;
        }
        
        if(deviceID<lib.getDeviceCount()){
            Ultrahaptics::DeviceInfo info = lib.getDeviceInfoByIndex(deviceID);
            const char* deviceName = info.getDeviceIdentifier();
            
            if(lib.isDeviceConnected(deviceName)){
                for(int i=x->nControlPoints-1; i>0; i--){
                    x->proxy[i] = proxy_new((t_object *)x, i, &x->proxy_inlet);
                }
                
                for(int i=0; i<x->nControlPoints;i++){
                    x->position[i] = Ultrahaptics::Vector3(0,0,0);
                    controlPoints[i].setPosition(x->position[i]);
                }
                post("Ultrahaptics for Max");
                post("Developed at Input Devices and Musical Interaction Laboratory (IDMIL)");
                post("McGill University");
                post("©Aditya T.B.,IDMIL, 2018");
                post("");
                post("Connected to Device: %s, Index Id: %ld", deviceName, deviceID);
            } else{
                object_error((t_object *) x,"Device found. Attempting to initialize",deviceName);
                uhptx_initialize(x);
            }
        } else {
            object_error((t_object *) x,"Device index doesn't exist. Number of available devices: %ld", lib.getDeviceCount());
        }
    } else {
        object_error((t_object *) x,"No devices found", lib.getDeviceCount());
    }
        
        
    return x;
}

void uhptx_clear(t_uhptx *x){}


void uhptx_assist(t_uhptx *x, void *b, long m, long a, char *s){
    switch(m){
        case 1:
            switch(a){
                case 0:
                    strncpy_zero(s, "Set parameters of Point 1 with a list input", 512);
                    break;
                case 1:
                    strncpy_zero(s, "Set parameters of Point 2 with a list input", 512);
                    break;
                case 2:
                    strncpy_zero(s, "Set parameters of Point 3 with a list input", 512);
                    break;
                case 3:
                    strncpy_zero(s, "Set parameters of Point 4 with a list input", 512);
                    break;
            }
            break;
    }
}



/****** Message Handling ******/


void uhptx_bang(t_uhptx *x){
    
    emitter.update(controlPoints, x->nControlPoints);

}

void uhptx_initialize(t_uhptx *x){
    int i = x->initialized;
    if(emitter.isConnected()){
        post("Emitter Connected");
    } else if(i<5){
            x->initialized++;
            object_warn((t_object *)x, "Attempting to connect to array. Ensure that device is connected via USB and powered on.");
            emitter.initialize();
            uhptx_initialize(x);
    } else {
        object_error((t_object *)x, "Timed out. Couldn't find Ultrahaptics array");
    }
}

void uhptx_test(t_uhptx *x){
    x->position[0] = Ultrahaptics::Vector3(0.08,0.08, 25 * Ultrahaptics::Units::centimetres);
    x->position[1] = Ultrahaptics::Vector3(-0.08,0.08, 20 * Ultrahaptics::Units::centimetres);
    x->position[2] = Ultrahaptics::Vector3(-0.08,-0.08, 15 * Ultrahaptics::Units::centimetres);
    x->position[3] = Ultrahaptics::Vector3(0.08,-0.08, 10 * Ultrahaptics::Units::centimetres);
    
    for (int i=0;i<x->nControlPoints;i++){
        x->point_intensity[i] = 1.0;
        x->frequency[i] = 150.0 * Ultrahaptics::Units::Hz;
    }
    
    uhptx_update(x);
    uhptx_bang(x);
    post("Initialized Emitter with 4 test points");
}



void uhptx_update(t_uhptx *x){
    
    for(int i=0;i<x->nControlPoints;i++){
        controlPoints[i].setPosition(x->position[i]);
        controlPoints[i].setFrequency(x->frequency[i]);
        controlPoints[i].setIntensity(x->point_intensity[i]);
    }

    post("Point information updated. Bang to emit");
}

void uhptx_stop(t_uhptx *x){
    emitter.stop();
    post("Emitter Stopped");
}


void uhptx_off(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    
    long inl = proxy_getinlet((t_object *) x);
    
    switch(inl){
        case 0:
            x->point_intensity[0] = 0.0;
            x->frequency[0] = 0.0;
            break;
        case 1:
            x->point_intensity[1] = 0.0;
            x->frequency[1] = 0.0;
            break;
        case 2:
            x->point_intensity[2] = 0.0;
            x->frequency[2] = 0.0;
            break;
        case 3:
            x->point_intensity[3] = 0.0;
            x->frequency[3] = 0.0;
            break;
    }

    
    uhptx_update(x);
    uhptx_bang(x);
}


void uhptx_reset(t_uhptx *x){
    
    for (int i=0;i<x->nControlPoints;i++){
        x->point_intensity[i] = 0.0;
        x->frequency[i] = 0.0;
    }
    uhptx_update(x);
    uhptx_bang(x);
    post("All Points Reset");
}

//Recieve list at each input, for respective point.
//List format: X, Y, Height, Intensity, Frequency


void uhptx_list(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    long inl = proxy_getinlet((t_object *) x);
    post("inlet %ld", inl);
    switch(inl){
        case 0:
            uhptx_pt1(x, s, argc, argv);
            break;
        case 1:
            uhptx_pt2(x, s, argc, argv);
            break;
        case 2:
            uhptx_pt3(x, s, argc, argv);
            break;
        case 3:
            uhptx_pt4(x, s, argc, argv);
            break;
    }
}


void uhptx_pt1(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    if(arg_check(x,argc, 1)){
        x->position[0].x = atom_getfloat(argv) * Ultrahaptics::Units::centimetres;
        x->position[0].y = atom_getfloat(argv + 1) * Ultrahaptics::Units::centimetres;
        x->position[0].z = atom_getfloat(argv + 2) * Ultrahaptics::Units::centimetres;
        x->point_intensity[0] = atom_getfloat((argv + 3));
        x->frequency[0] = atom_getfloat(argv + 4) * Ultrahaptics::Units::Hz;
        uhptx_update(x);
        post("%f",x->position[0].x);
    } else{
        post("args insufficient");
    }
}

void uhptx_pt2(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    if(arg_check(x,argc, 2)){
        x->position[1].x = atom_getfloat(argv) * Ultrahaptics::Units::centimetres;
        x->position[1].y = atom_getfloat(argv + 1) * Ultrahaptics::Units::centimetres;
        x->position[1].z = atom_getfloat(argv + 2) * Ultrahaptics::Units::centimetres;
        x->point_intensity[1] = atom_getfloat((argv + 3));
        x->frequency[1] = atom_getfloat(argv + 4) * Ultrahaptics::Units::Hz;
        uhptx_update(x);
    }
}

void uhptx_pt3(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    if(arg_check(x,argc, 3)){
        x->position[2].x = atom_getfloat(argv) * Ultrahaptics::Units::centimetres;
        x->position[2].y = atom_getfloat(argv + 1) * Ultrahaptics::Units::centimetres;
        x->position[2].z = atom_getfloat(argv + 2) * Ultrahaptics::Units::centimetres;
        x->point_intensity[2] = atom_getfloat((argv + 3));
        x->frequency[2] = atom_getfloat(argv + 4) * Ultrahaptics::Units::Hz;
        uhptx_update(x);
    }
}

void uhptx_pt4(t_uhptx *x, t_symbol *s, long argc, t_atom *argv){
    if(arg_check(x,argc, 4)){
        x->position[3].x = atom_getfloat(argv) * Ultrahaptics::Units::centimetres;
        x->position[3].y = atom_getfloat(argv + 1) * Ultrahaptics::Units::centimetres;
        x->position[3].z = atom_getfloat(argv + 2) * Ultrahaptics::Units::centimetres;
        x->point_intensity[3] = atom_getfloat((argv + 3));
        x->frequency[3] = atom_getfloat(argv + 4) * Ultrahaptics::Units::Hz;
        uhptx_update(x);
    }
}

bool arg_check(t_uhptx *x, long val, int point_id){
    if (val<5){
        object_error((t_object *)x, "Input List has too few arguments for Point %d. Ensure exactly 5 arguments.", point_id);
        return false;
    }
    else if (val>5){
        object_error((t_object *)x, "Input List has too many arguments for Point %d. Ensure exactly 5 arguments.", point_id);
        return false;
    }
    else{
        return true;
    }
}

