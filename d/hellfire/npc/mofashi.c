inherit NPC;
int give_magic();
void create()
{

        set_name("ħ��ʦ", ({ "magic wizard" }) );
        set("race", "����");
        set("age", 3000);
        set("long", "ӵ������ħ�����ħ��ʦ��\n");
        set("str", 20);
        set("cor", 30);
        set("max_force", 3000);
        set("mana", 5000);
        set("force", 5000);
        set("max_mana", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("verbs", ({ "bite", "claw"}) );
            set_temp("position/xx",18+random(5));
            set_temp("position/yy",18+random(5));
            set_temp("position/zz",0);

        set("combat_exp", 1000000+random(1000000));
        set("daoxing", 5000000);

       set_skill("dodge", 160);
       set_skill("unarmed", 100);
       set_skill("parry", 160);
       set_skill("moshenbu", 160);
       set_skill("force", 160);
       set_skill("wuxiangforce", 160);
       set_skill("sword", 200);
       set_skill("sanqing-jian", 200);
       set_skill("dao", 200);
       set_skill("spells", 200);
       map_skill("force", "wuxiangforce");
       map_skill("parry", "sanqing-jian");
       map_skill("sword", "sanqing-jian");
       map_skill("dodge", "moshenbu");
       map_skill("spells", "dao");
         set("hell_skill/dodge", 160);
         set("hell_skill/unarmed", 100);
         set("hell_skill/sword", 100);
         set("chat_chance_combat", 30);
         set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :)
       }));
        set_temp("apply/armor", 80);
        set_temp("apply/damage",80);
        set_temp("apply/armor_vs_force",300);
        set_weight(1000000);
        set("hell_type","ħ��ʦ");

            set("inquiry", ([
            "name"    : "���ǵ������ħ��ʦ��ӵ�����ϵ�ħ����",
            "magic"    :(:give_magic:),
            "ħ����"    :(:give_magic:),
               ]));
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

        carry_object("/d/obj/armor/tongjia")->wear();
}


void init()
{

        add_action("do_cast", "cast");
        add_action("do_perform", "perform");
        add_action("do_ji", "ji");

}

int give_magic()
{
        object me,who;
        me =this_object();
        who=this_player();
      if(who->query_temp("position/xx") != me->query_temp("position/xx") 
        || who->query_temp("position/yy") != me->query_temp("position/yy")) 
       {tell_object(who,"�㲻��"+me->name()+"��λ����ô��ѽ��\n");return 1;}

        if(me->is_fighting())
               { command("say ����������Ҫ����\n");return 1;}
        if(who->query("balance")<1000000)
                {tell_object(who,"��Ļƽ��������!\n");return 1;}
         tell_object(who,me->name()+"˵һ��������һ�Σ��ɸ�������ħ����2000�㣡�����ȷʵҪ��������yes,��������no��\n");
         input_to("get_com",who);
         return 1;
}


void die()
{
   return;
}
int get_com(string msg,object who)
{
        if(msg=="yes")
        {
                who->add("balance",-1000000);
                who->add("magic_pointed",2000);
                write("ħ��ʦ˵���ܸ��˺��㽻�ף���ʱΪ��Ч�͡�\n");
                return 1;
        }
        else if(msg=="no")
               {
                write("ħ��ʦ˵�������´���Ϊ��Ч�͡�\n");
                return 1;
        }
        write("ħ��ʦ˵һ��������һ�Σ��ɸ�������ħ����2000�㣡�����ȷʵҪ��������yes,��������no��\n");
       input_to("get_com",who);
        return 1;
}

int do_cast(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N�ſ��죬���ɰɵ����˼������\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who);
        return 1;
}



int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N��ɫ����ԣ�������ɱ����\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who);
        return 1;
}

int do_ji(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N͵͵��������������ʲô������\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who);
        return 1;
}

