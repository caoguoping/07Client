<GameFile>
  <PropertyGroup Name="dailyMission" Type="Node" ID="c520ec9f-a21a-4872-b73e-8fac5e2017f2" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="1.0000">
        <Timeline ActionTag="2130495609" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="180.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="40.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="2130495609" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="2130495609" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="614" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Image_38" ActionTag="-677860884" Alpha="191" Tag="720" IconVisible="False" LeftMargin="-8.0000" RightMargin="-8.0000" TopMargin="-4.5000" BottomMargin="-4.5000" TouchEnable="True" LeftEage="5" RightEage="5" TopEage="2" BottomEage="2" Scale9OriginX="5" Scale9OriginY="2" Scale9Width="6" Scale9Height="5" ctype="ImageViewObjectData">
            <Size X="16.0000" Y="9.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="60.0000" ScaleY="60.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="bg/bentouming.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="ImageFrame" ActionTag="2130495609" Tag="615" IconVisible="False" LeftMargin="-348.0000" RightMargin="-348.0000" TopMargin="-295.0000" BottomMargin="-215.0000" ctype="SpriteObjectData">
            <Size X="696.0000" Y="510.0000" />
            <Children>
              <AbstractNodeData Name="kuang02_2" ActionTag="108382791" Tag="616" IconVisible="False" LeftMargin="154.5508" RightMargin="179.4492" TopMargin="66.2974" BottomMargin="360.7026" ctype="SpriteObjectData">
                <Size X="362.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="335.5508" Y="402.2026" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4821" Y="0.7886" />
                <PreSize X="0.5201" Y="0.1627" />
                <FileData Type="Normal" Path="dailyMission/title_task.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ScrollView_1" ActionTag="-1681068820" Tag="2675" IconVisible="False" LeftMargin="23.1500" RightMargin="12.8500" TopMargin="170.5155" BottomMargin="19.4845" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
                <Size X="660.0000" Y="320.0000" />
                <Children>
                  <AbstractNodeData Name="Image_normal0" ActionTag="-682571476" Tag="284" IconVisible="False" LeftMargin="2.0708" RightMargin="493.9292" TopMargin="8.2863" BottomMargin="244.7137" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="1769264126" Tag="285" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" Visible="False" ActionTag="1458650178" Tag="286" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="-2087272038" Tag="287" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="945047381" Tag="288" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="143712584" Tag="289" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="1875804425" Tag="290" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="1894671987" Tag="291" IconVisible="False" LeftMargin="269.6658" RightMargin="20.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="3" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="14.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0461" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="2054391631" Tag="292" IconVisible="False" LeftMargin="112.8857" RightMargin="108.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="对局三局" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="83.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.2730" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="1589042129" Tag="293" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="1288891054" Tag="294" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" ActionTag="144868584" VisibleForFrame="False" Tag="295" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="-1224230216" VisibleForFrame="False" Tag="296" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="154.0708" Y="293.2137" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1926" Y="0.8378" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_normal1" ActionTag="287273296" Tag="297" IconVisible="False" LeftMargin="319.4384" RightMargin="176.5616" TopMargin="10.7444" BottomMargin="242.2556" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="194277047" Tag="298" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" ActionTag="1277973242" Tag="299" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="-262683664" Tag="300" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="1364808774" Tag="301" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="1347467199" Tag="302" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="-192354293" Tag="303" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="-1173569688" Tag="304" IconVisible="False" LeftMargin="265.6658" RightMargin="16.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="10" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="22.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0724" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="1851820169" Tag="305" IconVisible="False" LeftMargin="123.8857" RightMargin="119.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="赢10局" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="61.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.2007" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="537829094" Tag="306" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="787489051" Tag="307" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" ActionTag="-373699129" VisibleForFrame="False" Tag="308" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="1723824285" VisibleForFrame="False" Tag="309" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="471.4384" Y="290.7556" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5893" Y="0.8307" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_normal2" ActionTag="691304339" Tag="310" IconVisible="False" LeftMargin="2.0708" RightMargin="493.9292" TopMargin="113.1010" BottomMargin="139.8990" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="1093469387" Tag="311" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" ActionTag="750775016" Tag="312" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="-1528161846" Tag="313" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="-436853006" Tag="314" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="-696468988" Tag="315" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="1410087794" Tag="316" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="659856138" Tag="317" IconVisible="False" LeftMargin="269.6658" RightMargin="20.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="3" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="14.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0461" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="-1151496832" Tag="318" IconVisible="False" LeftMargin="112.8857" RightMargin="108.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="头游三局" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="83.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.2730" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="1792380235" Tag="319" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="-2075663327" Tag="320" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" CanEdit="False" ActionTag="-933422127" VisibleForFrame="False" Tag="321" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="-721598468" VisibleForFrame="False" Tag="322" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="154.0708" Y="188.3990" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1926" Y="0.5383" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_normal3" ActionTag="4056358" Tag="323" IconVisible="False" LeftMargin="319.4385" RightMargin="176.5615" TopMargin="113.2529" BottomMargin="139.7471" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="1905220227" Tag="324" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" ActionTag="1267684373" Tag="325" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="262714298" Tag="326" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="520580693" Tag="327" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="-2123506621" Tag="328" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="1316508288" Tag="329" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="532226283" Tag="330" IconVisible="False" LeftMargin="271.6658" RightMargin="22.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="10.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0329" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="-748443455" Tag="331" IconVisible="False" LeftMargin="92.8857" RightMargin="88.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="添加一位好友" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="123.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.4046" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="818682457" Tag="332" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="-521787559" Tag="333" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" ActionTag="2045597025" VisibleForFrame="False" Tag="334" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="-1878163112" VisibleForFrame="False" Tag="335" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="471.4385" Y="188.2471" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5893" Y="0.5378" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_normal4" ActionTag="406186736" Tag="336" IconVisible="False" LeftMargin="2.0708" RightMargin="493.9292" TopMargin="217.9158" BottomMargin="35.0842" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="-1238692742" Tag="337" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" ActionTag="1856858762" Tag="338" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="738542438" Tag="339" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="2057366502" Tag="340" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="-1855516978" Tag="341" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="-1903876876" Tag="342" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="-240466789" Tag="343" IconVisible="False" LeftMargin="271.6658" RightMargin="22.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="10.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0329" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="-1590955753" Tag="344" IconVisible="False" LeftMargin="102.8857" RightMargin="98.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="与好友比赛" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="103.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.3388" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="770071090" Tag="345" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="-187684941" Tag="346" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" ActionTag="-2178497" VisibleForFrame="False" Tag="347" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="1943780913" VisibleForFrame="False" Tag="348" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="154.0708" Y="83.5842" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1926" Y="0.2388" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_normal5" ActionTag="926510332" Tag="349" IconVisible="False" LeftMargin="319.4384" RightMargin="176.5616" TopMargin="215.7614" BottomMargin="37.2386" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="33" ctype="ImageViewObjectData">
                    <Size X="304.0000" Y="97.0000" />
                    <Children>
                      <AbstractNodeData Name="Button_get" ActionTag="-1643582643" Tag="350" IconVisible="False" LeftMargin="225.5356" RightMargin="6.4644" TopMargin="14.6488" BottomMargin="14.3512" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.5356" Y="48.3512" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8603" Y="0.4985" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_receive_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_receive_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Button_goto" ActionTag="-1082419262" Tag="351" IconVisible="False" LeftMargin="225.6770" RightMargin="6.3230" TopMargin="14.0997" BottomMargin="14.9003" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="46" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="72.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="261.6770" Y="48.9003" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8608" Y="0.5041" />
                        <PreSize X="0.2368" Y="0.7010" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="dailyMission/button_go_2.png" Plist="" />
                        <NormalFileData Type="Normal" Path="dailyMission/button_go_1.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_2" ActionTag="2094389936" Tag="352" IconVisible="False" LeftMargin="3.7477" RightMargin="216.2523" TopMargin="7.4261" BottomMargin="3.5739" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="30" Scale9Height="32" ctype="ImageViewObjectData">
                        <Size X="84.0000" Y="86.0000" />
                        <Children>
                          <AbstractNodeData Name="icon_gold_1_2" ActionTag="1742316168" Tag="353" IconVisible="False" LeftMargin="5.4687" RightMargin="0.5313" TopMargin="1.1100" BottomMargin="7.8900" ctype="SpriteObjectData">
                            <Size X="78.0000" Y="77.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="44.4687" Y="46.3900" />
                            <Scale ScaleX="0.7000" ScaleY="0.8337" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5294" Y="0.5394" />
                            <PreSize X="0.9286" Y="0.8953" />
                            <FileData Type="Normal" Path="bg/icon_gold_1.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="45.7477" Y="46.5739" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1505" Y="0.4801" />
                        <PreSize X="0.2763" Y="0.8866" />
                        <FileData Type="Normal" Path="dailyMission/item_frame_1.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now" ActionTag="70187185" Tag="354" IconVisible="False" LeftMargin="241.3997" RightMargin="47.6003" TopMargin="53.3494" BottomMargin="21.6506" FontSize="20" LabelText="0" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="15.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5788" ScaleY="0.6003" />
                        <Position X="250.0818" Y="34.8572" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8226" Y="0.3594" />
                        <PreSize X="0.0493" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_now_0" ActionTag="-1662764124" Tag="355" IconVisible="False" LeftMargin="250.9787" RightMargin="37.0213" TopMargin="53.7968" BottomMargin="21.2032" FontSize="20" LabelText=" / " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="16.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="258.9787" Y="32.2032" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8519" Y="0.3320" />
                        <PreSize X="0.0526" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_need" ActionTag="350548078" Tag="356" IconVisible="False" LeftMargin="271.6658" RightMargin="22.3342" TopMargin="53.2472" BottomMargin="21.7528" FontSize="20" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="10.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="276.6658" Y="32.7528" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.9101" Y="0.3377" />
                        <PreSize X="0.0329" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_description" ActionTag="-732038957" Tag="357" IconVisible="False" LeftMargin="112.8857" RightMargin="108.1143" TopMargin="14.9709" BottomMargin="60.0291" FontSize="20" LabelText="充值一次" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="83.0000" Y="22.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="154.3857" Y="71.0291" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="117" G="42" B="0" />
                        <PrePosition X="0.5078" Y="0.7323" />
                        <PreSize X="0.2730" Y="0.2268" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="text_bg_3" ActionTag="-16817827" Tag="358" IconVisible="False" LeftMargin="100.6938" RightMargin="88.3062" TopMargin="47.2828" BottomMargin="16.7172" ctype="SpriteObjectData">
                        <Size X="115.0000" Y="33.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.1938" Y="33.2172" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.3424" />
                        <PreSize X="0.3783" Y="0.3402" />
                        <FileData Type="Normal" Path="dailyMission/bg_text.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Text_reward" ActionTag="-1400806273" Tag="359" IconVisible="False" LeftMargin="123.1856" RightMargin="109.8144" TopMargin="55.9298" BottomMargin="23.0702" FontSize="16" LabelText="3000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="71.0000" Y="18.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="158.6856" Y="32.0702" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5220" Y="0.3306" />
                        <PreSize X="0.2336" Y="0.1856" />
                        <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_black" CanEdit="False" ActionTag="22573227" VisibleForFrame="False" Tag="360" IconVisible="False" LeftMargin="-0.1717" RightMargin="0.1717" TopMargin="-0.1332" BottomMargin="2.1332" LeftEage="116" RightEage="116" TopEage="32" BottomEage="32" Scale9OriginX="116" Scale9OriginY="32" Scale9Width="72" Scale9Height="31" ctype="ImageViewObjectData">
                        <Size X="304.0000" Y="95.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="151.8283" Y="49.6332" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4994" Y="0.5117" />
                        <PreSize X="1.0000" Y="0.9794" />
                        <FileData Type="Normal" Path="dailyMission/already-receive_2.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="Image_receive" ActionTag="954728947" VisibleForFrame="False" Tag="361" IconVisible="False" LeftMargin="255.7453" RightMargin="16.2547" TopMargin="32.2661" BottomMargin="32.7339" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
                        <Size X="32.0000" Y="32.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="271.7453" Y="48.7339" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.8939" Y="0.5024" />
                        <PreSize X="0.1053" Y="0.3299" />
                        <FileData Type="Normal" Path="bg/touming.png" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="471.4384" Y="85.7386" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5893" Y="0.2450" />
                    <PreSize X="0.3800" Y="0.2771" />
                    <FileData Type="Normal" Path="dailyMission/bg_task.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="23.1500" Y="19.4845" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0333" Y="0.0382" />
                <PreSize X="0.9483" Y="0.6275" />
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="255" G="150" B="100" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
                <InnerNodeSize Width="800" Height="350" />
              </AbstractNodeData>
              <AbstractNodeData Name="closeBtn" ActionTag="1499238738" Tag="349" IconVisible="False" LeftMargin="628.5710" RightMargin="-14.5710" TopMargin="78.9655" BottomMargin="351.0345" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="52" Scale9Height="58" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="82.0000" Y="80.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="669.5710" Y="391.0345" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.9620" Y="0.7667" />
                <PreSize X="0.1178" Y="0.1569" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="bg/anniu-guanbi-down.png" Plist="" />
                <NormalFileData Type="Normal" Path="bg/anniu-guanbi-up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="40.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="bg/bg_M.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>