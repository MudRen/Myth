inherit ROOM; 
#include <room.h> 
#include <ansi.h> 
void create () 
{
set("short","ɽ��");
set("long",@LONG 
����֮����ԭ�����죬ֻ�м�������֮�˷��ܳ��ɣ������˽�ν���ɺã���˭֪��
�����ѡ���
����һ�ۿ���ȥ����ɽ�øߺøߣ�����ӵ����ƶˣ���֪���������֪·�ںη���
��ɽ���������ߵģ���˵�����޵����ɵ����˼��Ÿ�����ȥ�ģ���û�޳ɵľ�ֻ������
ȥ�ˡ�
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
if (arg!="shan") return notify_fail("���������Ķ�ȥ��\n"); 
msg="$N";
if (ridee) msg=msg+"����"+ridee->query("name"); 
msg+="��ɽ����ȥ��\n";
message_vision(msg,me); 

damage=random(100); 
if (damage>me->query("eff_kee")-50) damage=me->query("eff_kee")-50; 
if (damage<=0) damage=0; 
me->receive_wound("kee",damage); 
me->move(dest); 
if (ridee) ridee->move(dest);
if (!damage) message_vision("$N����������һ��ɽͷ�ϣ�ȴ��֪����һ�������Ķ�ȥ�ˡ�\n",me); 
else { 
message_vision("$Nʹ���������ɽ�£�������Ъ�˿�����\n",me); 
COMBAT_D->report_status(me);  
} if (ridee) { 
message_vision("\n$N���ŵ�"+ridee->query("name")+"һ��С�ģ��������£�ˤ����һ�������",me); 
ridee->die(); 
}  me->start_busy(3+random(4)); 
return 1; 
}
