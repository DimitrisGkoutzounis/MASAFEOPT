    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (quarc_visualization_kuka_kr_5_P)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_client_
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_clien_o
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_server_
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_serve_d
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_initial
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_variabl
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_close_o
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VI
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_Hold
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VMax
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 3;

                    ;% quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_AMax
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 4;

                    ;% quarc_visualization_kuka_kr_5_P.PositionA_Value
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 5;

                    ;% quarc_visualization_kuka_kr_5_P.Gain_Gain
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 11;

                    ;% quarc_visualization_kuka_kr_5_P.Bias_Bias
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 12;

                    ;% quarc_visualization_kuka_kr_5_P.PositionB_Value
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 13;

                    ;% quarc_visualization_kuka_kr_5_P.DegreestoRadians_Gain
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 19;

                    ;% quarc_visualization_kuka_kr_5_P.IntegerDelay_InitialCondition
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 20;

                    ;% quarc_visualization_kuka_kr_5_P.IntegerDelay1_InitialCondition
                    section.data(12).logicalSrcIdx = 18;
                    section.data(12).dtTransOffset = 21;

                    ;% quarc_visualization_kuka_kr_5_P.PulseGenerator_Amp
                    section.data(13).logicalSrcIdx = 19;
                    section.data(13).dtTransOffset = 22;

                    ;% quarc_visualization_kuka_kr_5_P.PulseGenerator_Period
                    section.data(14).logicalSrcIdx = 20;
                    section.data(14).dtTransOffset = 23;

                    ;% quarc_visualization_kuka_kr_5_P.PulseGenerator_Duty
                    section.data(15).logicalSrcIdx = 21;
                    section.data(15).dtTransOffset = 24;

                    ;% quarc_visualization_kuka_kr_5_P.PulseGenerator_PhaseDelay
                    section.data(16).logicalSrcIdx = 22;
                    section.data(16).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_P.SystemTimebase_StopOnOverrun
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr_5_P.VisualizationInitialize_OpenVie
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (quarc_visualization_kuka_kr_5_B)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% quarc_visualization_kuka_kr_5_B.DegreestoRadians
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% quarc_visualization_kuka_kr_5_B.PulseGenerator
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (quarc_visualization_kuka_kr__DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.SystemTimebase_PreviousTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 3000;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Sigmoid
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 9000;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 9011;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 9012;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PPos
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 9013;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PVel
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 9014;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 9015;

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 9016;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Prev
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9017;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_b
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 9018;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_g
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 9019;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.VisualizationInitialize_PWORK
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_PWOR
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 2;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_PW_n
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 3;

                    ;% quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_PW_f
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.clockTickCounter
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4058088639;
    targMap.checksum1 = 1727139711;
    targMap.checksum2 = 233583810;
    targMap.checksum3 = 1734278102;

