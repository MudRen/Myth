//npc--laozhe

inherit NPC;

#include <ansi.h>

void create()
{
        set_name(HIW"��������"NOR, ({"baixu laozhe", "laozhe"}));
        set("age", 190);
        set("attitude", "peaceful");
        set("gender", "����");
        set("title", HIC"һ����ɽ"NOR);
        set("nickname", HIG"�ϵ���׳"NOR);
        set("str", 40);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_gin", 5000);
        set("max_kee",5000);
        set("max_sen", 5000);
        set("combat_exp", 10000000);
        set("daoxing", 10000000);


        set("force", 14000);
        set("max_force", 14000);
        set("force_factor", 500);
        set("mana",14000);
        set("max_mana", 14000);
        set("mana_factor", 400);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("spells", 250);
        set_skill("axe", 250);
        set_skill("sanban-axe",250);
        set_skill("lengquan-force",250);
        set_skill("baguazhou",250);
        set_skill("yanxing-steps",250);
        set_skill("changquan",250);
        map_skill("dodge","yanxing-steps");
        map_skill("unarmed","changquan");
        map_skill("force","lengquan-force");
        map_skill("spells","baguazhou");
        map_skill("axe","sanban-axe");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: perform_action,"axe", "kai" :),
        (: perform_action,"axe", "sanban" :),
        (: perform_action,"unarmed", "zhiqi" :),         
        }) );


        create_family("������", 2, "��");

       

        setup();

        add_money("silver", 50);

        carry_object("/d/obj/weapon/axe/huafu")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();

}

int accept_fight(object ob)
{
        object me = this_object();
        object who=this_player();

        if(me->is_fighting() )
                return notify_fail(HIW"��������"NOR+"����˵��û���Ϸ���æ����ô��\n");
        if( (int)me->query("kee")*100/(int)me->query("max_kee") < 70 )
                return notify_fail(HIW"��������"NOR+"����˵���Ϸ��左�������Ȳ��ã�����ʱ�������ɣ�\n");

        command("say �Ϸ������о��书û�պ����档\n");
        command("consider");
        command("say ����,����ôû�����㣿���Ķ����ã� \n");
        command("say ����ҹ���ȥ�� \n");
        message_vision(who->query("name") +"��" + HIW"��������"NOR +"һ�����˳�ȥ�� \n",me);
        who->move("/d/quest/bld/shanjiao");
        return 1;       
}

void kill_ob (object ob)
{
        set_temp("no_return",1);
        set_temp("my_killer",ob);
        ::kill_ob(ob);
}

void die()
{       
        object ob = query_temp("my_killer");
        object axe;
         if( !(axe = present("shen fu",ob)) && (ob->query("bld/mother") == 1))
{
        message_vision("��������һ�����������ɡ�\n"NOR,this_object());
        message_vision(HIW"��������"NOR+"����$Nһ�������� \n",ob);
        axe = new("/d/quest/bld/obj/shenfu");
        axe->move(ob);
        ob->set("bld/laozhe",1);
}
        
        message_vision("��Ҳ����ȥ�����ˡ�\n\n",this_object());
        message_vision(HIW"��������"NOR+"��������һ��̾�˿�����
\n\n",this_object());
        message_vision(HIW"��������"NOR+"˵���� ����������ǰ�ˣ�һ�����˻����ˣ��������ˣ� \n\n",this_object());
        message_vision(HIW"��������"NOR+"��������ȥ�� \n\n",this_object());
        destruct(this_object());
}


