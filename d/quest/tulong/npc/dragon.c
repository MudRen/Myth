inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
        set_name(HIR"�һ�����"NOR, ({ "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        set("long", 
"����һ��ȫ���죬�����֮��Ļ����������������
��ȫ��ɢ���ų��ɫ�Ļ��档\n");
        
        set("str", 248);
        set("con", 252);
        set("dex", 222);

        set("dodge", 5100);
        set("force", 5100);
        set("unarmed", 5100);
        set("parry", 5100);
        set("max_kee", 9999999);
        set("max_sen", 9999999);
        set("max_force", 901000);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(30)+10);
        set("chat_msg_combat", ({
        (: big_blowing :)
        }) );

                set("combat_exp", 901100000+random(600110000));
                set("bellicosity", 30000 );
        
        set_temp("apply/attack", 1560+random(400));
        set_temp("apply/damage",1500+random(400));
        set_temp("apply/armor", 1500+random(400));

        setup();
} 
int big_blowing()
{
        remove_call_out("hurting");
        message_vision( HIR "\n\n�һ��������������һ������ȫ��תΪ�ʺ�Ļ�ɫ�����������ʹ��˼�������\n\n" NOR,
        this_object());
        call_out("hurting",random(1)+1);


       return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n�һ������³�һ�ɳ�ɷٽ�Ļ��森����������ƺ�����ȼ���ţ�����\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(300)+100;
        if(dam <0) dam = 0;
        inv[i]->receive_wound("kee",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
void die()
{
        object obj;
        object me;
        obj = new("/d/quest/tulong/obj/drug");
        obj->move(environment(this_object()));
        obj = new("/d/quest/tulong/obj/drug");
        obj->move(environment(this_object())); 
        if(objectp(me=query_temp("last_damage_from") )); 
          tell_object(me, HIR "\n\nһ�Ż����͵����ڣ�һ������˵����лл��⿪�˵��ĸ���ӡ����������Ԫ����Ϊл��ɣ�����\n"NOR); 
        message("channel:chat", HBMAG"��������硿"+me->query("name")+"�ɹ���ɱ���˶������⿪�˷�ӡ��\n"NOR,users());

        {
            if(!me->query_temp("m_success/����"))
                  {
                me->set_temp("m_success/����",1);
                me->add("combat_exp",100000);
                me->add("daoxing",100000);
                me->add("potential",8000);
                 }
        }
        ::die();
} 


