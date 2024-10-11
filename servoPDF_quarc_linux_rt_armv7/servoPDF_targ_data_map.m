    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
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
        ;% Auto data (servoPDF_P)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% servoPDF_P.t_run
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.triangular_rep_seq_y
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% servoPDF_P.HILRead_analog_channels
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.HILWrite_analog_channels
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_P.HILRead_encoder_channels
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% servoPDF_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% servoPDF_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% servoPDF_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% servoPDF_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% servoPDF_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% servoPDF_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

                    ;% servoPDF_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 15;
                    section.data(11).dtTransOffset = 10;

                    ;% servoPDF_P.HILInitialize_POFrequency
                    section.data(12).logicalSrcIdx = 16;
                    section.data(12).dtTransOffset = 11;

                    ;% servoPDF_P.HILInitialize_POLeading
                    section.data(13).logicalSrcIdx = 17;
                    section.data(13).dtTransOffset = 12;

                    ;% servoPDF_P.HILInitialize_POTrailing
                    section.data(14).logicalSrcIdx = 18;
                    section.data(14).dtTransOffset = 13;

                    ;% servoPDF_P.HILInitialize_POInitial
                    section.data(15).logicalSrcIdx = 19;
                    section.data(15).dtTransOffset = 14;

                    ;% servoPDF_P.countstorad_Gain
                    section.data(16).logicalSrcIdx = 20;
                    section.data(16).dtTransOffset = 15;

                    ;% servoPDF_P.Constant2_Value
                    section.data(17).logicalSrcIdx = 21;
                    section.data(17).dtTransOffset = 16;

                    ;% servoPDF_P.step_Amp
                    section.data(18).logicalSrcIdx = 22;
                    section.data(18).dtTransOffset = 17;

                    ;% servoPDF_P.step_Period
                    section.data(19).logicalSrcIdx = 23;
                    section.data(19).dtTransOffset = 18;

                    ;% servoPDF_P.step_Duty
                    section.data(20).logicalSrcIdx = 24;
                    section.data(20).dtTransOffset = 19;

                    ;% servoPDF_P.step_PhaseDelay
                    section.data(21).logicalSrcIdx = 25;
                    section.data(21).dtTransOffset = 20;

                    ;% servoPDF_P.magnituderad_Gain
                    section.data(22).logicalSrcIdx = 26;
                    section.data(22).dtTransOffset = 21;

                    ;% servoPDF_P.Constant_Value
                    section.data(23).logicalSrcIdx = 27;
                    section.data(23).dtTransOffset = 22;

                    ;% servoPDF_P.LookUpTable1_bp01Data
                    section.data(24).logicalSrcIdx = 28;
                    section.data(24).dtTransOffset = 23;

                    ;% servoPDF_P.Constant_Value_b
                    section.data(25).logicalSrcIdx = 29;
                    section.data(25).dtTransOffset = 28;

                    ;% servoPDF_P.FilteredDerivative_A
                    section.data(26).logicalSrcIdx = 30;
                    section.data(26).dtTransOffset = 29;

                    ;% servoPDF_P.FilteredDerivative_C
                    section.data(27).logicalSrcIdx = 31;
                    section.data(27).dtTransOffset = 30;

                    ;% servoPDF_P.FilteredDerivative_D
                    section.data(28).logicalSrcIdx = 32;
                    section.data(28).dtTransOffset = 31;

                    ;% servoPDF_P.Constant1_Value
                    section.data(29).logicalSrcIdx = 33;
                    section.data(29).dtTransOffset = 32;

                    ;% servoPDF_P.Saturation1_UpperSat
                    section.data(30).logicalSrcIdx = 34;
                    section.data(30).dtTransOffset = 33;

                    ;% servoPDF_P.Saturation1_LowerSat
                    section.data(31).logicalSrcIdx = 35;
                    section.data(31).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% servoPDF_P.HILInitialize_EIInitial
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.HILInitialize_POModes
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_P.HILInitialize_POConfiguration
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_P.HILInitialize_POAlignment
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_P.HILInitialize_POPolarity
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% servoPDF_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 45;
                    section.data(5).dtTransOffset = 5;

                    ;% servoPDF_P.HILInitialize_POChannels
                    section.data(6).logicalSrcIdx = 46;
                    section.data(6).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% servoPDF_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 48;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 49;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 50;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 51;
                    section.data(5).dtTransOffset = 4;

                    ;% servoPDF_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 52;
                    section.data(6).dtTransOffset = 5;

                    ;% servoPDF_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 53;
                    section.data(7).dtTransOffset = 6;

                    ;% servoPDF_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 54;
                    section.data(8).dtTransOffset = 7;

                    ;% servoPDF_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 55;
                    section.data(9).dtTransOffset = 8;

                    ;% servoPDF_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 56;
                    section.data(10).dtTransOffset = 9;

                    ;% servoPDF_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 57;
                    section.data(11).dtTransOffset = 10;

                    ;% servoPDF_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 58;
                    section.data(12).dtTransOffset = 11;

                    ;% servoPDF_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 59;
                    section.data(13).dtTransOffset = 12;

                    ;% servoPDF_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 60;
                    section.data(14).dtTransOffset = 13;

                    ;% servoPDF_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 61;
                    section.data(15).dtTransOffset = 14;

                    ;% servoPDF_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 62;
                    section.data(16).dtTransOffset = 15;

                    ;% servoPDF_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 63;
                    section.data(17).dtTransOffset = 16;

                    ;% servoPDF_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 64;
                    section.data(18).dtTransOffset = 17;

                    ;% servoPDF_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 65;
                    section.data(19).dtTransOffset = 18;

                    ;% servoPDF_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 66;
                    section.data(20).dtTransOffset = 19;

                    ;% servoPDF_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 67;
                    section.data(21).dtTransOffset = 20;

                    ;% servoPDF_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 68;
                    section.data(22).dtTransOffset = 21;

                    ;% servoPDF_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 69;
                    section.data(23).dtTransOffset = 22;

                    ;% servoPDF_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 70;
                    section.data(24).dtTransOffset = 23;

                    ;% servoPDF_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 71;
                    section.data(25).dtTransOffset = 24;

                    ;% servoPDF_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 72;
                    section.data(26).dtTransOffset = 25;

                    ;% servoPDF_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 73;
                    section.data(27).dtTransOffset = 26;

                    ;% servoPDF_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 74;
                    section.data(28).dtTransOffset = 27;

                    ;% servoPDF_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 75;
                    section.data(29).dtTransOffset = 28;

                    ;% servoPDF_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 76;
                    section.data(30).dtTransOffset = 29;

                    ;% servoPDF_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 77;
                    section.data(31).dtTransOffset = 30;

                    ;% servoPDF_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 78;
                    section.data(32).dtTransOffset = 31;

                    ;% servoPDF_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 79;
                    section.data(33).dtTransOffset = 32;

                    ;% servoPDF_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 80;
                    section.data(34).dtTransOffset = 33;

                    ;% servoPDF_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 81;
                    section.data(35).dtTransOffset = 34;

                    ;% servoPDF_P.HILRead_Active
                    section.data(36).logicalSrcIdx = 82;
                    section.data(36).dtTransOffset = 35;

                    ;% servoPDF_P.HILWrite_Active
                    section.data(37).logicalSrcIdx = 83;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% servoPDF_P.Switch_CurrentSetting
                    section.data(1).logicalSrcIdx = 84;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
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
        ;% Auto data (servoPDF_B)
        ;%
            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% servoPDF_B.countstorad
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_B.Clock
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_B.magnituderad
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_B.theta_d
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_B.ModelArgument
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% servoPDF_B.FilteredDerivative
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% servoPDF_B.ModelArgument1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% servoPDF_B.u
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% servoPDF_B.Vm
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

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
        nTotSects     = 5;
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
        ;% Auto data (servoPDF_DW)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% servoPDF_DW.HILInitialize_AOVoltages
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_DW.HILInitialize_FilterFrequency
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_DW.HILInitialize_POSortedFreqs
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% servoPDF_DW.HILInitialize_POValues
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% servoPDF_DW.HILRead_AnalogBuffer
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% servoPDF_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% servoPDF_DW.HILRead_PWORK
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_DW.HILWrite_PWORK
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% servoPDF_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% servoPDF_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% servoPDF_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% servoPDF_DW.ToWorkspace5_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 6;

                    ;% servoPDF_DW.ToWorkspace8_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 7;

                    ;% servoPDF_DW.controlsignal_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% servoPDF_DW.HILInitialize_DOStates
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% servoPDF_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% servoPDF_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 3;

                    ;% servoPDF_DW.HILRead_EncoderBuffer
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 5;

                    ;% servoPDF_DW.clockTickCounter
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% servoPDF_DW.HILInitialize_POSortedChans
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
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


    targMap.checksum0 = 3931983829;
    targMap.checksum1 = 3282753930;
    targMap.checksum2 = 2208456370;
    targMap.checksum3 = 308127812;

