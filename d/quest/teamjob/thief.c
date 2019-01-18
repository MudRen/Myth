//ħ������
//thief.c


#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot);
int do_back(object me);

void create()
{
      string weapon;
        set_name("������", ({ "mengmian ren","ren","thief"}));
        set("gender", "����");
        set("title", HIR"ħ������"NOR);
        set("class", "yaomo");
        set("family/family_name", "�ݿ�ɽ�޵׶�");
        set("age", random(30) + 100);
        set("str", 40);
        set("con", 40);
        set("int", 40);
        set("dex", 40);
        set("long", "һ�����ź�ɫҹ���µ��ˣ���������������͸��һ��������\n");
        set("combat_exp", 50000000 + random(40000000)); 
        set("daoxing", 50000000 + random(40000000)); 
        set("attitude", "friendly");
        set_skill("force", 500);
        set_skill("sword", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("unarmed", 500);
        set_skill("blade", 500);
        set_skill("yinfeng-zhua", 500);
        set_skill("qixiu-jian", 500); 
        set_skill("huntian-qigong",500);
        set_skill("lingfu-steps",500);
        set_skill("kugu-blade",500);
        set_skill("spells",500);
        set_skill("yaofa",500);
        map_skill("dodge", "kugu-blade");
        map_skill("sword", "qixiu-jian");
        map_skill("parry", "kugu-blade");
        map_skill("blade", "kugu-blade");
        map_skill("unarmed", "yinfeng-zhua");
        map_skill("force", "huntian-qigong");
        map_skill("spells", "yaofa");
        
        set("max_kee", 10000); 
        set("kee", 10000);
        set("max_sen", 10000);
        set("sen", 10000); 
        set("force", 20000); 
        set("max_force", 20000);
        set("max_mana", 20000);
        set("mana", 20000);
        set("force_factor", 350);
        set("mana_factor", 350);
        set("chat_chance_combat", 100); 
        set("chat_msg_combat", ({ 
           (: perform_action, "blade", "sword" :), 
           (: perform_action, "blade", "pozhan" :), 
           (: perform_action, "blade", "diyu" :), 
           (: perform_action, "sword", "yaowu" :),
           (: perform_action, "sword", "kuangsha" :),
           (: perform_action, "unarmed", "duo" :),
           (: cast_spell, "suliao" :),  
        }) ); 

        setup();
        weapon = random(2)?"/d/sanjie/obj/leidao":"/d/npc/obj/sword";
        carry_object(weapon)->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        i = i +20+ random(20);
        if( i < 400) i = 400;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set("daoxing", (me->query("daoxing")+random(me->query("daoxing")))*2);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("unarmed", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("spells", i);
        ob->set_skill("qixiu-jian", i);       
        ob->set_skill("yinfeng-zhua", i); 
        ob->set_skill("huntian-qigong",i);
        ob->set_skill("kugu-blade", i);
        ob->set_skill("yaofa", i);
        ob->set("max_kee", 2000+i*30); 
        ob->set("max_sen", me->query("eff_sen")*2/3); 
        ob->set("max_force", 3000+i*40);
        ob->set("max_mana", 2000+i*20); 
        ob->set("force_factor", i/6);
        ob->reincarnate(); 
        ob->set("kee",ob->query("max_kee"));
        ob->set("sen",ob->query("max_sen"));
        ob->set("force",ob->query("max_force"));
        ob->set("mana",ob->query("max_mana"));
        call_out("do_back", 200,  ob);  
        return 1;
}

int do_back(object me)
{                       
        tell_room(environment(me), me->query("name")+"����һ��������ʧ�ˡ�\n", ({me}));    
        destruct(me); 
        return 1;
}


