inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","清风细雨楼第三层——梅花轩");
  set ("long", MAG@LONG


                             山   园   小   梅




    众芳摇落独暄妍，占尽风情向小园          琼姿只合在瑶台，谁向江南处处栽

    淑影横斜水清浅，暗香浮动月黄昏          雪满山中寒霜落，月明林下美人来

    霜禽欲下先偷眼，粉蝶如知合断魂          寒依淑影萧萧竹，春掩残香漠漠苔

    幸有微吟可相狎，不须檀板共金樽          自去何郎无好韵，东风愁寂几回开




LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou4",
  "down" : __DIR__"qingfenglou2",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
