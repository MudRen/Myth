#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name("自由女神", ({ "ziyou nushen", "nushen"}));
   set("title", HIC"三界神话"HIR"嘉峪关站"NOR);
  set("long", HIW"\n一位娇柔万分的女子，伶俐地扭动着腰肢。\n手举自由火把，有关于自由的事，可以问问她。\n"NOR+HIC"\n ask nushen about pk 选择ＰＫ的道路。\n ask nushen about nopk 选择ＮＯＰＫ的道路。\n ask nushen about gift 拿取取经完成大闹天宫过关的奖励。\n ask nushen about back 对你的人生选择有一次重新选择的机会。\n\n"NOR);
  set("color", HIW);
  set("gender", "女性");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 12000);
  set("force_factor", 300);
  set("max_mana", 7000);
  set("mana", 16000);
  set("mana_factor", 350);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);
  set("inquiry", ([
  "name" : "我就是本站的自由女神，你可以从我这儿要奖励(gift)。\n",
/*
  "here" : "你可以选择“pk”或者“nopk”来决定你以后的人生。\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  "back" : (:back:),
  "反悔" : (:back:),
*/
  "gift" : (:gift:),
  "奖励" : (:gift:),
  ]));
  setup();
}

int pk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("pk")=="pk")
{
message_vision("自由女神对着$N说：“你的人生已经决定了，你还想变改？”\n",who);
return 1;
}
else
{
str=who->name();
message_system("自由女神："+str+"已经选择了PK这条道路，望大家知照。");
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了PK这条道路，以后好自为之啦。”\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
return 1;
}
}

int nopk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("PKS")>3)
{
message_vision("自由女神对着$N说：你杀人过多无法保证你的安全，你去吧！”\n",who);
return 1;
}
if (this_player()->query("ziyou")=="got")
{
message_vision("自由女神对着$N说：“你的人生已经决定了，你还想变改？”\n",who);
return 1;
}
else
{
str=who->name();
message_system("自由女神："+str+"已经选择了NOPK这条道路，大家以后不要再为难他了。");
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了NOPK这条道路，以后请多帮别人的忙。”\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}
}

int gift()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyougift")=="got")	
{
message_vision("自由女神对着$N说：“你已经拿过了，做人不要太贪心好。”\n",who);
return 1;
}
else
if (this_player()->query("obstacle/number") < 34 )
{
message_vision("自由女神对着$N说：“你西天取经还没有完成，请多加努力。”\n",who);
return 1;
}
else
if (this_player()->query("dntg/number") < 10 )
{
message_vision("自由女神对着$N说：“你大闹天宫还没有完成，成功在向你招手啊。”\n",who);
return 1;
}
else
{
str=who->name();
message_system("自由女神："+str+"已经过西天取经、大闹天宫等难关，特此奖励。");
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你已经过西天取经、大闹天宫等难关，特此奖励。”\n\n"HIC"$N得到20万武学、500年道行、150两黄金、所有基本属性加2点的奖励。\n"NOR,who);
who->add("combat_exp", 200000 );
who->add("daoxing", 500000 );
who->add("potential", 100000 );
who->add("balance", 1500000 );
who->add("str", 2 );
who->add("cor", 2 );
who->add("int", 2 );
who->add("spi", 2 );
who->add("cps", 2 );
who->add("per", 2 );
who->add("con", 2 );
who->add("kar", 2 );
who->set("ziyougift", "got" );
return 1;
}
}

int back()
{
string str;
object who = this_player();
object ob = this_object();

if (who->query("PKS") > 0)
{
message_vision("自由女神对着$N说：“人都杀过了，还要怎么样？”\n",who);
return 1;
}
if (this_player()->query("ziyouback")=="got")
{
message_vision("自由女神对着$N说：“你的人生已经反悔一次了，做人还是不要太反复无常好？”\n",who);
return 1;
}
else
{
str=who->name();
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经重新选择你的人生道路。”\n",who);
who->delete("ziyouchoose");
who->delete("nopk");
who->delete("pk");
who->set("ziyouback","got");
PKMANAGER_D->change_choose(who);
return 1;
}
}

