{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 34.0, 79.0, 1111.0, 748.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "<none>",
		"showontab" : 1,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-75",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 629.0, 425.0, 106.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 588.0, 501.0, 106.0, 22.0 ],
					"style" : "",
					"text" : "r controlSubPatch"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-73",
					"linecount" : 7,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 629.0, 282.0, 246.0, 100.0 ],
					"presentation" : 1,
					"presentation_linecount" : 7,
					"presentation_rect" : [ 589.0, 332.0, 246.0, 100.0 ],
					"style" : "",
					"text" : "1. Connect Device as shown in the manual.\n2. UHEV1 Array is usually 16cm x 16cm in dimensions.\n3. X and Y co-ordinates are created from -8cm to 8cm on UHEV1 array. i.e, 0,0\n4. Height of a point is stated to be felt up to 80cms above the array."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 228.0, 395.5, 233.0, 60.0 ],
					"presentation" : 1,
					"presentation_linecount" : 4,
					"presentation_rect" : [ 188.0, 445.5, 233.0, 60.0 ],
					"style" : "",
					"text" : "switch off only the point that receives this message. Send to the corresponding inlet. This can also be done by setting the point intensity to 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 228.0, 342.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 188.0, 392.0, 150.0, 20.0 ],
					"style" : "",
					"text" : "Reset all points to 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-67",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 228.0, 286.5, 233.0, 33.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 188.0, 336.5, 233.0, 33.0 ],
					"style" : "",
					"text" : "Stop emitting everything, but don't reset the existing point information."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 228.0, 223.5, 211.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 3,
					"presentation_rect" : [ 188.0, 273.5, 211.0, 47.0 ],
					"style" : "",
					"text" : "The test message initializes all four points at the four corners of the array, each at different heights."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-61",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 228.0, 159.5, 237.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 3,
					"presentation_rect" : [ 188.0, 209.5, 237.0, 47.0 ],
					"style" : "",
					"text" : "In case there is some error in using the device, the init message attempts to re-establish a connection with the device."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"linecount" : 11,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 627.0, 49.0, 233.0, 154.0 ],
					"presentation" : 1,
					"presentation_linecount" : 11,
					"presentation_rect" : [ 587.0, 99.0, 233.0, 154.0 ],
					"style" : "",
					"text" : "The list is formatted as follows:\n\n1. The first 3 numbers represent x, y, and z co-ordinates in cms (where z is height above the array).\n2. The 4th element of the list is the modulation or point intensity, normalized between 0 and 1.\n3. The 5th and final element of the list is the modulating frequency in Hz. Strong points are felt around 100-200Hz."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 662.0, 14.0, 213.0, 33.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 622.0, 64.0, 213.0, 33.0 ],
					"style" : "",
					"text" : "A point is created in space with a list of numbers"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 241.0, 14.0, 252.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 201.0, 64.0, 252.0, 20.0 ],
					"style" : "",
					"text" : "Bang updates all the points on the device"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 241.0, 88.0, 271.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 3,
					"presentation_rect" : [ 201.0, 138.0, 271.0, 47.0 ],
					"style" : "",
					"text" : "If using a metro, the update rate should not be set less than 10ms to ensure proper working of the devices"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-40",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 583.0, 14.0, 77.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 543.0, 64.0, 77.0, 22.0 ],
					"style" : "",
					"text" : "0 0 15 1 100"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.75, 408.0, 29.5, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 429.75, 458.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "off"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.75, 348.0, 37.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 429.75, 398.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "reset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-34",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.75, 292.0, 33.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 429.75, 342.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 508.0, 14.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 468.0, 64.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.75, 236.0, 30.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 429.75, 286.0, 30.0, 22.0 ],
					"style" : "",
					"text" : "test"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.75, 172.0, 29.5, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 429.75, 222.0, 29.5, 22.0 ],
					"style" : "",
					"text" : "init"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 598.0, 495.5, 231.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 3,
					"presentation_rect" : [ 558.0, 545.5, 231.0, 47.0 ],
					"style" : "",
					"text" : "If using multiple devices, enter a postive, non-zero number as argument. No argument defaults to 1 device."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 247.75, 495.5, 273.0, 33.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 207.75, 545.5, 273.0, 33.0 ],
					"style" : "",
					"text" : "There can only be one object per each physical device being connected.",
					"textcolor" : [ 0.784314, 0.145098, 0.023529, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.011765, 0.396078, 0.752941, 0.65098 ],
					"color" : [ 0.682353, 0.705882, 0.776471, 1.0 ],
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 4,
					"numoutlets" : 0,
					"patching_rect" : [ 524.75, 495.5, 70.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 484.75, 545.5, 70.0, 22.0 ],
					"style" : "",
					"text" : "uhptx.am 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 526.0, 95.0, 58.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 486.0, 145.0, 58.0, 22.0 ],
					"style" : "",
					"text" : "metro 10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 526.0, 65.0, 24.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 486.0, 115.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-74",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 4,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 59.0, 104.0, 650.0, 480.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"showontab" : 1,
						"visible" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 272.0, 471.0, 108.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 272.0, 471.0, 108.0, 22.0 ],
									"style" : "",
									"text" : "s controlSubPatch"
								}

							}
, 							{
								"box" : 								{
									"floatoutput" : 1,
									"id" : "obj-28",
									"maxclass" : "dial",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 414.0, 78.0, 50.0, 50.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 414.0, 78.0, 50.0, 50.0 ],
									"size" : 25.0,
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 292.0, 324.0, 29.5, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 292.0, 324.0, 29.5, 22.0 ],
									"style" : "",
									"text" : "* 8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 129.0, 324.0, 29.5, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 129.0, 324.0, 29.5, 22.0 ],
									"style" : "",
									"text" : "* 8"
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-29",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 292.0, 348.0, 50.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 622.0, 388.0, 50.0, 22.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-27",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 129.0, 348.0, 50.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 564.0, 388.0, 50.0, 22.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "newobj",
									"numinlets" : 5,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 272.0, 426.0, 97.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 272.0, 426.0, 97.0, 22.0 ],
									"style" : "",
									"text" : "pak 0. 0. 0. 0. 0."
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-24",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 414.0, 237.0, 50.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 414.0, 237.0, 50.0, 22.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"floatoutput" : 1,
									"id" : "obj-22",
									"maxclass" : "dial",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 414.0, 185.0, 50.0, 50.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 414.0, 185.0, 50.0, 50.0 ],
									"size" : 200.0,
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-18",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 414.0, 130.0, 50.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 414.0, 130.0, 50.0, 22.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"format" : 6,
									"id" : "obj-11",
									"maxclass" : "flonum",
									"numinlets" : 1,
									"numoutlets" : 2,
									"outlettype" : [ "", "bang" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 369.0, 292.0, 37.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 745.0, 388.0, 37.0, 22.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"floatoutput" : 1,
									"id" : "obj-9",
									"maxclass" : "slider",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 369.0, 63.0, 37.0, 227.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 369.0, 63.0, 37.0, 227.0 ],
									"size" : 25.0,
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"patching_rect" : [ 292.0, 298.0, 41.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 292.0, 298.0, 41.0, 22.0 ],
									"style" : "",
									"text" : "/ 100."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"patching_rect" : [ 129.0, 298.0, 41.0, 22.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 129.0, 298.0, 41.0, 22.0 ],
									"style" : "",
									"text" : "/ 100."
								}

							}
, 							{
								"box" : 								{
									"bottomvalue" : -100,
									"id" : "obj-19",
									"leftvalue" : -100,
									"maxclass" : "pictslider",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "int", "int" ],
									"parameter_enable" : 0,
									"patching_rect" : [ 129.0, 50.0, 227.0, 227.0 ],
									"presentation" : 1,
									"presentation_rect" : [ 129.0, 50.0, 227.0, 227.0 ],
									"rightvalue" : 100,
									"style" : "",
									"topvalue" : 100
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 2 ],
									"source" : [ "obj-11", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"source" : [ "obj-12", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 3 ],
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-20", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"midpoints" : [ 346.5, 308.0, 301.5, 308.0 ],
									"source" : [ "obj-19", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-20", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-21", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-24", 0 ],
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 4 ],
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-1", 0 ],
									"source" : [ "obj-25", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 0 ],
									"source" : [ "obj-27", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-25", 1 ],
									"source" : [ "obj-29", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-9", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 990.0, 25.0, 57.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 973.0, 526.0, 57.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p control"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 535.5, 490.25, 534.25, 490.25 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 517.5, 491.75, 534.25, 491.75 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 2 ],
					"midpoints" : [ 592.5, 435.25, 568.25, 435.25 ],
					"source" : [ "obj-40", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "uhptx.am.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
