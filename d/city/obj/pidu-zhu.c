//Creat by waiwai@2001/03/03
//Last modified by waiwai@2001/06/20

#include <ansi.h>

inherit ITEM;

void create()
{
set_name(HIW"天界"HIB"辟毒珠"NOR,({"pidu-zhu"}));
set("long","这是这是一颗世间难得的宝珠,可以用来解"HIR"（ｃｕｒｅ）"NOR"毒！\n");
set("unit","颗");
set("no_put",1);
set("no_drop",1);
set("no_sell",1);
set("no_give",1);
set("no_get",1);
set("no_break",1);//By waiwai@2001/06/20
set("can_auction",1);
set("is_monitored",1);
}

void init()
{
if(this_player()==environment()) add_action("do_cure","cure");
}

int do_cure()
{
object me;me=this_player();

message_vision("$N将辟毒珠放到伤处滚了几下!\n",me);
me->clear_condition();
message_vision("$N只觉腹内一阵清凉直透全身经脉!\n",me);
return 1;
}

int query_autoload() { return 1; }

