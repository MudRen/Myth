//ˮ��
#include <ansi.h>
inherit NPC;
int big_blowing();
void create()
{
       set_name("����", ({"jiao long","jiao"}));
       set("long", "�����߽�������Ĺ�������ޱȣ���˵����������һ��������
����֮����Ϊ����һƬ��\n");
       set("age", 1783);
       set("attitude", "aggressive");
       set("per", 10);
       set("max_kee", 10000);
       set("max_gin", 3000);
       set("max_sen", 6000);
       set("max_mana", 3000);
       set("mana", 1500);
       set("limbs", ({ "ͷ��", "����", "β��" }) );
       set("verbs", ({ "bite", "claw" }) );
       set("chat_chance_combat", random(80));
       set("chat_msg_combat", ({
 (: big_blowing :)
        }) );

       set("combat_exp", 2000000+random(2000000));
       set_temp("apply/attack", 160+random(300));
       set_temp("apply/damage",100+random(100));
       set_temp("apply/armor", 340+random(400));
       setup();
}
int big_blowing()
{
remove_call_out("hurting");
message_vision( HIC "\n\n$N�����͵�һ�ţ�ȫ����ѩ�Ƶİף�ɢ���Ŵ̹ǵĺ�����
\n\n" NOR,this_object());
call_out("hurting",random(10)+2);
 return 1;
}
int hurting()
{
 int i;
 int dam;
 object *inv;
 message_vision( HIR "\n\n$N�³�һ�ɺ�������̶ˮ��Ҫ����ס�ˣ�����\n\n",this_object());
 inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
 if( living(inv[i]))
 if( inv[i] != this_object())
 {
 dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_spells");
 if(dam <0) dam = 0;
 inv[i]->receive_wound("kee",dam);
 COMBAT_D->report_status(inv[i],1);
        }
 return 1;
}

void die()
{
 object me,ob;

 if(objectp(me=query_temp("last_damage_from") ))
    if(me->query("liyiru/kill_jiaolong"))
    {
     me->set("liyiru/killed_jiaolong",1);
     me->delete("liyiru/kill_jiaolong");
    }
 ::die();
}
