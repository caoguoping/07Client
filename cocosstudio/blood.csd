<GameFile>
  <PropertyGroup Name="blood" Type="Node" ID="35d5ec08-5a86-475b-be95-eaa3fa122a51" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="1.0000">
        <Timeline ActionTag="-145566830" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="180.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="40.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-145566830" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-145566830" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="1088" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Image_bg" ActionTag="-1701805847" Alpha="204" Tag="457" IconVisible="False" LeftMargin="-8.0000" RightMargin="-8.0000" TopMargin="-4.5000" BottomMargin="-4.5000" TouchEnable="True" LeftEage="5" RightEage="5" TopEage="2" BottomEage="2" Scale9OriginX="5" Scale9OriginY="2" Scale9Width="6" Scale9Height="5" ctype="ImageViewObjectData">
            <Size X="16.0000" Y="9.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="60.0000" ScaleY="60.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="bg/bentouming.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Image_frame" ActionTag="-145566830" Tag="458" IconVisible="False" LeftMargin="-348.0000" RightMargin="-348.0000" TopMargin="-295.0000" BottomMargin="-215.0000" TouchEnable="True" LeftEage="5" RightEage="5" TopEage="2" BottomEage="2" Scale9OriginX="5" Scale9OriginY="2" Scale9Width="686" Scale9Height="506" ctype="ImageViewObjectData">
            <Size X="696.0000" Y="510.0000" />
            <Children>
              <AbstractNodeData Name="Image_cloud" ActionTag="1553815791" Tag="512" IconVisible="False" LeftMargin="14.5093" RightMargin="40.4907" TopMargin="375.0911" BottomMargin="14.9089" LeftEage="86" RightEage="86" TopEage="22" BottomEage="22" Scale9OriginX="86" Scale9OriginY="22" Scale9Width="469" Scale9Height="76" ctype="ImageViewObjectData">
                <Size X="641.0000" Y="120.0000" />
                <AnchorPoint />
                <Position X="14.5093" Y="14.9089" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0208" Y="0.0292" />
                <PreSize X="0.9210" Y="0.2353" />
                <FileData Type="Normal" Path="bg/bg_cloud.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_1_0_0" ActionTag="1986651309" Tag="459" IconVisible="False" LeftMargin="-60.4828" RightMargin="-18.5172" TopMargin="318.3073" BottomMargin="-3.3073" LeftEage="86" RightEage="86" TopEage="22" BottomEage="22" Scale9OriginX="86" Scale9OriginY="22" Scale9Width="603" Scale9Height="151" ctype="ImageViewObjectData">
                <Size X="775.0000" Y="195.0000" />
                <AnchorPoint />
                <Position X="-60.4828" Y="-3.3073" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="-0.0869" Y="-0.0065" />
                <PreSize X="1.1135" Y="0.3824" />
                <FileData Type="Normal" Path="blood/decoration.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_1" ActionTag="413312729" Tag="1106" IconVisible="False" LeftMargin="22.6989" RightMargin="476.3011" TopMargin="183.5636" BottomMargin="63.4364" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="167" Scale9Height="241" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="197.0000" Y="263.0000" />
                <Children>
                  <AbstractNodeData Name="Text_gold" ActionTag="-455950078" Tag="1107" IconVisible="False" LeftMargin="29.5164" RightMargin="119.4836" TopMargin="108.8136" BottomMargin="132.1864" FontSize="20" LabelText="底注: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="53.5164" Y="143.1864" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2717" Y="0.5444" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_gold_0" ActionTag="1116651046" Tag="1108" IconVisible="False" LeftMargin="30.4359" RightMargin="118.5641" TopMargin="136.9737" BottomMargin="104.0263" FontSize="20" LabelText="入局: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="54.4359" Y="115.0263" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2763" Y="0.4374" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_dizhu" ActionTag="-1042924099" Tag="1109" IconVisible="False" LeftMargin="81.1469" RightMargin="82.8531" TopMargin="109.0617" BottomMargin="131.9383" FontSize="20" LabelText="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="33.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="97.6469" Y="142.9383" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.4957" Y="0.5435" />
                    <PreSize X="0.1675" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_ruju" ActionTag="278946089" Tag="1110" IconVisible="False" LeftMargin="81.3367" RightMargin="39.6633" TopMargin="138.1237" BottomMargin="102.8763" FontSize="20" LabelText="500金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="76.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="119.3367" Y="113.8763" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.6058" Y="0.4330" />
                    <PreSize X="0.3858" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="121.1989" Y="194.9364" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1741" Y="0.3822" />
                <PreSize X="0.2830" Y="0.5157" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <NormalFileData Type="Normal" Path="blood/bg_fight_5.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_2" ActionTag="1672120999" Tag="1113" IconVisible="False" LeftMargin="231.1069" RightMargin="267.8931" TopMargin="183.5632" BottomMargin="63.4368" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="167" Scale9Height="241" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="197.0000" Y="263.0000" />
                <Children>
                  <AbstractNodeData Name="Text_gold" ActionTag="1876048951" Tag="1114" IconVisible="False" LeftMargin="29.5166" RightMargin="119.4834" TopMargin="108.8128" BottomMargin="132.1872" FontSize="20" LabelText="底注: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="53.5166" Y="143.1872" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2717" Y="0.5444" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_gold_0" ActionTag="-655658344" Tag="1115" IconVisible="False" LeftMargin="30.4376" RightMargin="118.5624" TopMargin="136.9725" BottomMargin="104.0275" FontSize="20" LabelText="入局: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="54.4376" Y="115.0275" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2763" Y="0.4374" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_dizhu" ActionTag="1703116268" Tag="1116" IconVisible="False" LeftMargin="79.1500" RightMargin="80.8500" TopMargin="109.0605" BottomMargin="131.9395" FontSize="20" LabelText="600" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="37.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="97.6500" Y="142.9395" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.4957" Y="0.5435" />
                    <PreSize X="0.1878" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_ruju" ActionTag="893339606" Tag="1117" IconVisible="False" LeftMargin="77.8387" RightMargin="32.1613" TopMargin="138.1219" BottomMargin="102.8781" FontSize="20" LabelText="2000金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="87.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="121.3387" Y="113.8781" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.6159" Y="0.4330" />
                    <PreSize X="0.4416" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="329.6069" Y="194.9368" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4736" Y="0.3822" />
                <PreSize X="0.2830" Y="0.5157" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <NormalFileData Type="Normal" Path="blood/bg_fight_10.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_3" ActionTag="61269097" Tag="1120" IconVisible="False" LeftMargin="449.7219" RightMargin="49.2781" TopMargin="191.2126" BottomMargin="55.7874" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="167" Scale9Height="241" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="197.0000" Y="263.0000" />
                <Children>
                  <AbstractNodeData Name="Text_gold" ActionTag="353300399" Tag="1121" IconVisible="False" LeftMargin="29.5180" RightMargin="119.4820" TopMargin="108.8129" BottomMargin="132.1871" FontSize="20" LabelText="底注: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="53.5180" Y="143.1871" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2717" Y="0.5444" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_gold_0" ActionTag="-1211440463" Tag="1122" IconVisible="False" LeftMargin="30.4377" RightMargin="118.5623" TopMargin="136.9723" BottomMargin="104.0277" FontSize="20" LabelText="入局: " ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="54.4377" Y="115.0277" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.2763" Y="0.4374" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_dizhu" ActionTag="-116847449" Tag="1123" IconVisible="False" LeftMargin="82.6506" RightMargin="66.3494" TopMargin="109.0604" BottomMargin="131.9396" FontSize="20" LabelText="3000" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="48.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="106.6506" Y="142.9396" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.5414" Y="0.5435" />
                    <PreSize X="0.2437" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_ruju" ActionTag="-1552812638" Tag="1124" IconVisible="False" LeftMargin="84.3461" RightMargin="42.6539" TopMargin="138.1220" BottomMargin="102.8780" FontSize="20" LabelText="1万金币" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="70.0000" Y="22.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="119.3461" Y="113.8780" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="163" G="76" B="0" />
                    <PrePosition X="0.6058" Y="0.4330" />
                    <PreSize X="0.3553" Y="0.0837" />
                    <FontResource Type="Normal" Path="font/fangzhengchuyuan.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="548.2219" Y="187.2874" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7877" Y="0.3672" />
                <PreSize X="0.2830" Y="0.5157" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <NormalFileData Type="Normal" Path="blood/bg_fight_end.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_1_0" ActionTag="1447774881" Tag="1105" IconVisible="False" LeftMargin="147.5346" RightMargin="186.4654" TopMargin="-39654.0000" BottomMargin="40003.0000" LeftEage="86" RightEage="86" TopEage="22" BottomEage="22" Scale9OriginX="86" Scale9OriginY="22" Scale9Width="190" Scale9Height="117" ctype="ImageViewObjectData">
                <Size X="362.0000" Y="161.0000" />
                <AnchorPoint />
                <Position X="147.5346" Y="40003.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2120" Y="78.4373" />
                <PreSize X="0.5201" Y="0.3157" />
                <FileData Type="Normal" Path="blood/title_fight.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_close" ActionTag="432158877" Tag="460" IconVisible="False" LeftMargin="623.6990" RightMargin="-9.6990" TopMargin="82.3044" BottomMargin="347.6956" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="52" Scale9Height="58" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="82.0000" Y="80.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="664.6990" Y="387.6956" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.9550" Y="0.7602" />
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
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>