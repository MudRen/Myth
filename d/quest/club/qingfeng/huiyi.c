#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();

void create ()
{
  set ("short", "清风细雨楼——会议大厅");
  set ("long", HIW@LONG




   ★ *     .     *          ☆★ *     .     * ★            ★ *     . 
   *       ★     *   ☆.        ★ *     .    *        *     *☆

  *       ★     *   ☆.        ★ *     .    *        *     *☆
     ★ *     .     *          ☆★ *     .     * ★            ★ *     . 

    走进清风细雨会议室，眼前一亮，灯火辉煌。这里是帮主和几位长老开会议事的  
    地方。左右两面墙壁上挂着华丽的壁毯，下面并排的排放着几张龙头虎爪椅，这 
    是几位长老的座椅，中间的天花板上挂着一盏由东海龙宫探寻来的夜明珠，光辉 
    四射，正前方摆着一把檀香碧玉椅，听说这把椅子是当年玉皇大帝让工匠开凿通 
    天神路的时候，从一金刚山中寻觅到的一块檀香玉石雕琢而成的。细看此椅，上 
    面似乎有一(organ)机关。




LONG NOR);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"qingfenglou5",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "organ" : "
一个做得很精细的密码盘，似乎是（niu），知密码者生，窃进者死，切记，切记.......
",
]));

set("objects", ([ /* sizeof() == 1 */
                "/d/kaifeng/npc/xiaotong" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodseat" : 1,
               "/d/moon/obj/woodtable" : 1,
               "/d/obj/其他/高脚椅" : 1,
                "/d/kaifeng/npc/yahuan" : 1,
        ]));

  setup();
}
void init()
{
  add_action("do_turn", "niu");
  add_action("do_turn", "zhuan");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要转什么？\n");
  if(arg=="organ")
    return notify_fail("请输入相应的密码！\n譬如：turn 1 或 turn 1234。。。\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="丹丹姐姐")
    {
      message_vision(HIW "只见一道闪电从密码轮中窜出，直向$N扑来！\n" NOR, me);
      if (mykee>0)
        {
          me->set_temp("death_msg", "擅自进去清风细雨楼帮主密室，被一道闪电劈中，去见了阎罗王。\n");
          me->die();
          me->save();
          return 1;
    }                                                      
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N显然伤得不轻！\n" NOR, me); 
      return 1;
    }          
  else
    {
      message_vision("只听“叮咚”的一声，一道小门开启，$N身不由己被推进帮主暗室去了！\n", me);
      me->move(__DIR__"miroom");
      return 1;
    }
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
