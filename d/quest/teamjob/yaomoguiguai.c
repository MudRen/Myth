#include <ansi.h>
inherit NPC;

string *names = ({
    HIB"���ñ�"NOR,
    HIB"��Ѫ�����"NOR,
    HIB"�������"NOR,
    HIB"����"NOR,
    HIB"���"NOR,
    HIB"����"NOR,
    HIB"��ţ��"NOR,
    HIB"������ħ"NOR,
    HIB"�»�Ұ��"NOR,
    HIB"�Ʒ��"NOR,
    HIB"��������"NOR,
});

int do_copy(object me,int maxpot,int type);

void create()
{
        string weapon;
        set_name(names[random(sizeof(names))], ({ "yaomo guiguai ","yaomo","guiguai"}));
        set("gender", "����");
        set("title",WHT"ħ�����");
        set("age", random(20) + 100);
        set("family/family_name", "������"); 
        set("str", 40);
        set("con", 40);
        set("int", 40);
        set("dex", 40);
        set("combat_exp", 80000 + random(40000)); 
        set("daoxing", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("spear", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("axe", 250);
        set_skill("spells", 250);
        set_skill("changquan", 250);
        set_skill("lengquan-force", 250);
        set_skill("sanban-axe", 250+random(100));
        set_skill("dengxian-dafa", 250);
        set_skill("bawang-qiang", 250); 
        set_skill("yanxing-steps",250);
        set_skill("bawang-qiang", 250+random(100));
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("axe", "sanban-axe");
        map_skill("dodge", "yanxing-steps");
        map_skill("spells", "dengxin-dafa");
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        set_temp("apply/damage", 150);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "spear", "jinghun" :),
                (: perform_action, "spear", "bugong" :),
                (: perform_action, "axe", "sanban" :),
        }) );
        set("max_kee", 3500); 
        set("max_sen", 3500); 
        set("force", 5000); 
        set("max_force", 5000);
        set("force_factor", 100);
        set("max_mana",5000);
        set("mana",5000);
        set("mana_factor",200);
        weapon = random(2)?"/d/obj/weapon/spear/jinqiang":"/d/obj/weapon/axe/huafu";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
                i = i + 10 + random(20);
        else  
                i = i + 50 + random(30);

        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp"))));
        ob->set("daoxing", (me->query("daoxing")*3/2+random(me->query("daoxing"))*2));
        ob->set_skill("force", i);
        ob->set_skill("spear", i);
        ob->set_skill("unarmed",  i);
        ob->set_skill("axe", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("spells", i);       
        ob->set_skill("lengquan-force", i); 
        ob->set_skill("bawang-qiang",i);
        ob->set_skill("changquan",i);
        ob->set_skill("sanban-axe",i);
        ob->set_skill("yanxing-steps",i);
        ob->set_skill("dengxian-dafa",i);
        ob->set("max_kee",     i*15); 
        ob->set("max_sen", me->query("max_sen")*4/3); 
        ob->set("max_force",  i*20); 
        ob->set("force_factor", i/3);
        if(type==3)
                {ob->set("max_kee",     i*30);
                 ob->set("max_force",  i*35); 
                }
        if(type==2)
                {ob->set("max_kee",     i*20); 
                 ob->reincarnate(); 
                 ob->set("kee",ob->query("max_kee"));
                 ob->set("force",ob->query("max_force"));
                }
            return 1;
}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "��ʧ��һƬ���֮�С�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

