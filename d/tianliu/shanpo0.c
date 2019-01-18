inherit ROOM; 
#include <room.h> 
#include <ansi.h> 
void create () 
{
set("short","山坡");
set("long",@LONG 
修仙之道，原本渺渺，只有极大毅力之人方能成仙，“世人皆谓神仙好，有谁知道
成仙难。“
　　一眼看上去，这山好高好高，好象接到了云端，不知道云深几许，不知路在何方。
这山本不是用走的，据说真正修道成仙的是人架着浮云上去的，还没修成的就只有爬上
去了。
LONG);
setup();
}
void init() {
add_action("do_climb","climb");
}
int do_climb(string arg) { 
object me=this_player(),ridee=me->ride(); 
int damage; 
string dest=__DIR__"shanpo"+(string)(random(18))+".c"; 
string msg; 
if (!arg) return 0; 
if (arg!="shan") return notify_fail("你想爬到哪儿去？\n"); 
msg="$N";
if (ridee) msg=msg+"骑着"+ridee->query("name"); 
msg+="往山上爬去。\n";
message_vision(msg,me); 

damage=random(100); 
if (damage>me->query("eff_kee")-50) damage=me->query("eff_kee")-50; 
if (damage<=0) damage=0; 
me->receive_wound("kee",damage); 
me->move(dest); 
if (ridee) ridee->move(dest);
if (!damage) message_vision("$N艰苦的爬到另一个山头上，却不知道下一步该往哪儿去了。\n",me); 
else { 
message_vision("$N痛苦的爬上了山坡，坐下来歇了口气。\n",me); 
COMBAT_D->report_status(me);  
} if (ridee) { 
message_vision("\n$N骑着的"+ridee->query("name")+"一不小心，掉下悬崖，摔成了一团肉饼。",me); 
ridee->die(); 
}  me->start_busy(3+random(4)); 
return 1; 
}
