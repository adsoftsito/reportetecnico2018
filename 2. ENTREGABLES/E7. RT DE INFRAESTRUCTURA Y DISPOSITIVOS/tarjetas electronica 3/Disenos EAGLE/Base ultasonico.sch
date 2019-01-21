<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="CONECTORES RODAS">
<packages>
<package name="RJ11">
<wire x1="0" y1="0" x2="14.05" y2="0" width="0.6096" layer="21"/>
<wire x1="14.05" y1="0" x2="14.05" y2="18.8" width="0.6096" layer="21"/>
<wire x1="14.05" y1="18.8" x2="0" y2="18.8" width="0.6096" layer="21"/>
<wire x1="0" y1="18.8" x2="0" y2="15.85" width="0.6096" layer="21"/>
<wire x1="0" y1="15.85" x2="0" y2="0" width="0.6096" layer="21"/>
<wire x1="0" y1="15.85" x2="13.88" y2="15.85" width="0.6096" layer="21"/>
<wire x1="0.0495" y1="6.1379" x2="13.9637" y2="6.1379" width="0.6096" layer="21"/>
<wire x1="13.9637" y1="6.1379" x2="13.9637" y2="6.0897" width="0.127" layer="21"/>
<circle x="1.9824" y="10.4978" radius="0.9083" width="1.4224" layer="21"/>
<circle x="12.1538" y="10.5244" radius="0.9083" width="1.4224" layer="21"/>
<pad name="2" x="8.9789" y="4.1529" drill="1" diameter="1.778"/>
<pad name="1" x="6.4262" y="4.1529" drill="1" diameter="1.778"/>
<pad name="3" x="5.1562" y="1.651" drill="1" diameter="1.778"/>
<pad name="4" x="7.6581" y="1.6256" drill="1" diameter="1.778"/>
<pad name="H1" x="1.9939" y="10.5029" drill="1.4" diameter="3.2"/>
<pad name="H2" x="12.1412" y="10.5029" drill="1.4" diameter="3.2"/>
<text x="2.4321" y="19.6722" size="1.778" layer="25">&gt;NAME</text>
<text x="-0.7851" y="4.81" size="1.778" layer="27" rot="R90">&gt;VALUE</text>
</package>
<package name="ULTRASONICO">
<wire x1="0" y1="0" x2="17.13021875" y2="0" width="0.8128" layer="21"/>
<wire x1="17.13021875" y1="0" x2="45" y2="0" width="0.8128" layer="21"/>
<wire x1="45" y1="0" x2="45" y2="20" width="0.8128" layer="21"/>
<wire x1="45" y1="20" x2="0" y2="20" width="0.8128" layer="21"/>
<wire x1="0" y1="20" x2="0" y2="0" width="0.8128" layer="21"/>
<pad name="TRIG" x="21.24583125" y="2.783840625" drill="1.2" diameter="1.778" shape="long" rot="R90"/>
<pad name="ECHO" x="23.78583125" y="2.783840625" drill="1.2" diameter="1.778" shape="long" rot="R90"/>
<pad name="GND" x="26.32583125" y="2.783840625" drill="1.2" diameter="1.778" shape="long" rot="R90"/>
<pad name="VCC" x="18.70583125" y="2.783840625" drill="1.2" diameter="1.778" shape="long" rot="R90"/>
<wire x1="17.13021875" y1="5.08" x2="17.13021875" y2="0" width="0.6096" layer="21"/>
<wire x1="17.13021875" y1="0" x2="27.94" y2="0" width="0.127" layer="21"/>
<wire x1="27.94" y1="0" x2="27.94" y2="5.08" width="0.6096" layer="21"/>
<wire x1="27.94" y1="5.08" x2="17.13021875" y2="5.08" width="0.6096" layer="21"/>
<circle x="7.8636875" y="11.5284375" radius="6.35" width="0.127" layer="21"/>
<circle x="7.8636875" y="11.57724375" radius="6.35" width="0.8128" layer="21"/>
<circle x="7.812190625" y="11.62659375" radius="3.5921" width="1.4224" layer="21"/>
<circle x="37.154475" y="11.5284375" radius="6.35" width="0.127" layer="21"/>
<circle x="37.154475" y="11.5284375" radius="6.35" width="0.8128" layer="21"/>
<circle x="37.102978125" y="11.62659375" radius="3.5921" width="1.4224" layer="21"/>
<text x="19.4706625" y="5.5617875" size="1.27" layer="21" rot="R90">VCC</text>
<text x="21.926421875" y="5.5617875" size="1.27" layer="21" rot="R90">TRIG</text>
<text x="24.557596875" y="5.5617875" size="1.27" layer="21" rot="R90">ECHO</text>
<text x="27.18876875" y="5.5617875" size="1.27" layer="21" rot="R90">GND</text>
<text x="17.073371875" y="12.645746875" size="1.6764" layer="21">HC - SR04</text>
<circle x="1.28634375" y="18.675896875" radius="0.706659375" width="0.127" layer="21"/>
<circle x="1.28634375" y="1.287996875" radius="0.706659375" width="0.127" layer="21"/>
<circle x="43.67743125" y="18.73445625" radius="0.706659375" width="0.127" layer="21"/>
<circle x="43.735903125" y="1.288009375" radius="0.706659375" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="RJ11">
<wire x1="0" y1="17.78" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.254" layer="94"/>
<wire x1="10.16" y1="0" x2="10.16" y2="17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="17.78" x2="0" y2="17.78" width="0.254" layer="94"/>
<text x="9.3142" y="20.1244" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="-2.281" y="13.6094" size="1.778" layer="96" rot="R270">&gt;VALUE</text>
<pin name="H1" x="2.54" y="-5.08" length="middle" swaplevel="1" rot="R90"/>
<pin name="H2" x="7.62" y="-5.08" length="middle" swaplevel="2" rot="R90"/>
<pin name="1" x="15.24" y="15.24" length="middle" swaplevel="3" rot="R180"/>
<pin name="2" x="15.24" y="12.7" length="middle" swaplevel="4" rot="R180"/>
<pin name="3" x="15.24" y="10.16" length="middle" swaplevel="5" rot="R180"/>
<pin name="4" x="15.24" y="7.62" length="middle" swaplevel="6" rot="R180"/>
</symbol>
<symbol name="ULTRASONICO">
<pin name="GND" x="-5.08" y="17.78" length="middle" swaplevel="1"/>
<pin name="ECHO" x="-5.08" y="12.7" length="middle" swaplevel="2"/>
<pin name="TRIG" x="-5.08" y="7.62" length="middle" swaplevel="3"/>
<pin name="VCC" x="-5.08" y="2.54" length="middle" swaplevel="4"/>
<wire x1="0" y1="20.32" x2="12.7" y2="20.32" width="0.254" layer="94"/>
<wire x1="12.7" y1="20.32" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="20.32" width="0.254" layer="94"/>
<text x="10.16" y="22.86" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="RJ11">
<gates>
<gate name="G$1" symbol="RJ11" x="0" y="0" swaplevel="6"/>
</gates>
<devices>
<device name="" package="RJ11">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="H1" pad="H1"/>
<connect gate="G$1" pin="H2" pad="H2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ULTRASONICO">
<gates>
<gate name="G$1" symbol="ULTRASONICO" x="0" y="0" swaplevel="4"/>
</gates>
<devices>
<device name="" package="ULTRASONICO">
<connects>
<connect gate="G$1" pin="ECHO" pad="ECHO"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="TRIG" pad="TRIG"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="holes">
<description>&lt;b&gt;Mounting Holes and Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2,8-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 2.8 mm, round</description>
<wire x1="0" y1="2.921" x2="0" y2="2.667" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.667" x2="0" y2="-2.921" width="0.0508" layer="21"/>
<wire x1="-1.778" y1="0" x2="0" y2="-1.778" width="2.286" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="1.778" x2="1.778" y2="0" width="2.286" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.635" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="2.921" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="39"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="40"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="43"/>
<circle x="0" y="0" radius="1.5" width="0.2032" layer="21"/>
<pad name="B2,8" x="0" y="0" drill="2.8" diameter="5.334"/>
</package>
<package name="3,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.0 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="39"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.6" width="0.2032" layer="21"/>
<pad name="B3,0" x="0" y="0" drill="3" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,0</text>
</package>
<package name="3,2-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.2 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.1524" layer="21"/>
<pad name="B3,2" x="0" y="0" drill="3.2" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,2</text>
</package>
<package name="3,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.3 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.2032" layer="21"/>
<pad name="B3,3" x="0" y="0" drill="3.3" diameter="5.842"/>
</package>
<package name="3,6-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.6 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.9" width="0.2032" layer="21"/>
<pad name="B3,6" x="0" y="0" drill="3.6" diameter="5.842"/>
</package>
<package name="4,1-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.1 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.572" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="5.08" width="2" layer="43"/>
<circle x="0" y="0" radius="2.15" width="0.2032" layer="21"/>
<pad name="B4,1" x="0" y="0" drill="4.1" diameter="8"/>
</package>
<package name="4,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.3 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.25" width="0.1524" layer="21"/>
<pad name="B4,3" x="0" y="0" drill="4.3" diameter="9"/>
</package>
<package name="4,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.35" width="0.1524" layer="21"/>
<pad name="B4,5" x="0" y="0" drill="4.5" diameter="9"/>
</package>
<package name="5,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.0 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.6" width="0.1524" layer="21"/>
<pad name="B5" x="0" y="0" drill="5" diameter="9"/>
</package>
<package name="5,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.85" width="0.1524" layer="21"/>
<pad name="B5,5" x="0" y="0" drill="5.5" diameter="9"/>
</package>
</packages>
<symbols>
<symbol name="MOUNT-PAD">
<wire x1="0.254" y1="2.032" x2="2.032" y2="0.254" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="0.254" x2="-0.254" y2="2.032" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="-0.254" x2="-0.254" y2="-2.032" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<wire x1="0.254" y1="-2.032" x2="2.032" y2="-0.254" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<circle x="0" y="0" radius="1.524" width="0.0508" layer="94"/>
<text x="2.794" y="0.5842" size="1.778" layer="95">&gt;NAME</text>
<text x="2.794" y="-2.4638" size="1.778" layer="96">&gt;VALUE</text>
<pin name="MOUNT" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOUNT-PAD-ROUND" prefix="H">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt;, round</description>
<gates>
<gate name="G$1" symbol="MOUNT-PAD" x="0" y="0"/>
</gates>
<devices>
<device name="2.8" package="2,8-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B2,8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.0" package="3,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,0"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.2" package="3,2-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.3" package="3,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.6" package="3,6-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.1" package="4,1-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.3" package="4,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.5" package="4,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.0" package="5,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.5" package="5,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5,5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="ULTRASONICO" library="CONECTORES RODAS" deviceset="RJ11" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="SENSOR_NIVEL" library="CONECTORES RODAS" deviceset="ULTRASONICO" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="H1" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.0"/>
<part name="H2" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.0"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="ULTRASONICO" gate="G$1" x="2.54" y="5.08"/>
<instance part="GND1" gate="1" x="30.48" y="10.16"/>
<instance part="SENSOR_NIVEL" gate="G$1" x="55.88" y="5.08"/>
<instance part="GND2" gate="1" x="38.1" y="17.78"/>
<instance part="H1" gate="G$1" x="0" y="-5.08"/>
<instance part="H2" gate="G$1" x="33.02" y="-5.08"/>
</instances>
<busses>
</busses>
<nets>
<net name="D1" class="0">
<segment>
<pinref part="ULTRASONICO" gate="G$1" pin="1"/>
<wire x1="17.78" y1="20.32" x2="22.86" y2="20.32" width="0.1524" layer="91"/>
<label x="22.86" y="20.32" size="1.4224" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="SENSOR_NIVEL" gate="G$1" pin="TRIG"/>
<wire x1="50.8" y1="12.7" x2="45.72" y2="12.7" width="0.1524" layer="91"/>
<label x="45.72" y="12.7" size="1.4224" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="ULTRASONICO" gate="G$1" pin="2"/>
<wire x1="17.78" y1="17.78" x2="22.86" y2="17.78" width="0.1524" layer="91"/>
<label x="22.86" y="17.78" size="1.4224" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="SENSOR_NIVEL" gate="G$1" pin="VCC"/>
<wire x1="50.8" y1="7.62" x2="45.72" y2="7.62" width="0.1524" layer="91"/>
<label x="45.72" y="7.62" size="1.4224" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="D2" class="0">
<segment>
<pinref part="ULTRASONICO" gate="G$1" pin="4"/>
<wire x1="17.78" y1="12.7" x2="22.86" y2="12.7" width="0.1524" layer="91"/>
<label x="22.86" y="12.7" size="1.4224" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="SENSOR_NIVEL" gate="G$1" pin="ECHO"/>
<wire x1="50.8" y1="17.78" x2="45.72" y2="17.78" width="0.1524" layer="91"/>
<label x="45.72" y="17.78" size="1.4224" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="ULTRASONICO" gate="G$1" pin="3"/>
<wire x1="17.78" y1="15.24" x2="30.48" y2="15.24" width="0.1524" layer="91"/>
<wire x1="30.48" y1="15.24" x2="30.48" y2="12.7" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="SENSOR_NIVEL" gate="G$1" pin="GND"/>
<wire x1="50.8" y1="22.86" x2="38.1" y2="22.86" width="0.1524" layer="91"/>
<wire x1="38.1" y1="22.86" x2="38.1" y2="20.32" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
