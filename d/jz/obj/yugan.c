//Cracked by Roath
//yugan.c

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���", ({"yu gan"}));
        set_weight(1000);
                set("unit", "��");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N��$n�������У�\n");

        setup();
}
void init()
{
  add_action("do_fish", "fish");        
}
int do_fish()
{
   object me=this_player();
     string env;
    if( me->query("fish") )
        return notify_fail("�����ڲ����ڵ���\n");
if(interactive(me) &&me->query("combat_exp") >100000 )
        return notify_fail("�㻹��ȥ�ҵ���������ɰɣ���������ø�С���ɰɡ�\n");
    if ( time() - me->query("last_fish") < 30 )
        return notify_fail("�ҿ��㻹�ǹ����������ɡ�\n");
    if(me->is_busy())
        return notify_fail("����æ���أ�\n");
if((int)me->query("kee") <80)
        return notify_fail("�����ھ���״�����ã��ǵ���������ģ�\n");
    me->set("fish");
    message_vision( CYN "$N�������������һ˦���ѹ���˦���˺��м䡣\n" NOR, me);
    me->start_busy(5);
    call_out("zhai1",1,me);
    call_out("zhai2",3+random(2),me);
    call_out("finish_zhai",5,me);
    return 1;
}
void zhai1(object me)
{
   message_vision( GRN "$N�����㸡�����������������û�ж�����\n"NOR, me);
}
void zhai2(object me)
{
   message_vision( YEL "$N�����㸡������һ�£���ϸ���������Ϲ��ˣ�\n", 
me); 
}
void finish_zhai(object me)
{
   object ob;    
   if ( random(3) == 1) {
   tell_object(me,"�浹ù����ʲôҲû�е�������\n");
   return 0;  }
   if ( me->query("combat_exp") < 1000000 ) {
   if ( me->query("combat_exp") < 10000 )
   ob = new("/d/jz/obj/fish1");
   if ( me->query("combat_exp") < 100000)
   ob = new("/d/jz/obj/fish2");
   else 
   ob = new("/d/jz/obj/fish3");
        }   
   ob->move(environment(me));      
   tell_object(me,"�������һ��" + ob->query("name") +"��\n");
   me->add("combat_exp",50+random(50));
   me->add("potential",2);
   me->delete("fish");
   me->set("last_fish",time());
}                                                 
