//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/jinchi.c
 
inherit NPC;
string ask_jiasha();

void create()
{
        set_name("��س���", ({"jin chi","monk","jinchi"}));
        set("long", "һ������ȥ�ܴ�����Ϻ��С�\n");

        set("gender", "����");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 150);
        set("combat_exp", 300000);
        set("daoxing",2000000);
        set("per", 25);
        set("max_kee", 500);
        set("kee",500);
        set("max_sen",500);
        set("sen",500);
        set("force", 1000);
        set("force_factor", 50);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("spells",80);
        set_skill("buddhism", 100);
        set_skill("unarmed", 80);
        set_skill("jienan-zhi", 70);
        set_skill("lotusmove", 60);
        set_skill("lotusforce", 80);
        set_skill("staff", 80);
        set_skill("lunhui-zhang", 80);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("inquiry", ([
        "����": (: ask_jiasha :),
        "jiasha": (: ask_jiasha :),
        ]));
        
        setup();
        carry_object("/d/obj/weapon/staff/chanzhang")->wield();
        carry_object("/d/qujing/heifeng/obj/cloth")->wear();
        setup();
}

string ask_jiasha()
{
         object ob = this_player();

        if( ob->query_temp("fired") )
                {
                command("fear");
                return("����....����....���Ĳ����ˡ�");
                }
        if( ob->query("obstacle/hf") == "done" 
         || ob->query_temp("see_jiasha"))
                return("��λʩ�������Ѿ�������������\n");


        command("haha");
        command("knock wall");
        ob->set_temp("see_jiasha",1);
        return("�����������ģ����Ҷ����ˡ�\n");

}

int accept_object(object who, object ob)
{
                if( (string)ob->query("id") == "wucai jiasha"
                   && who->query_temp("see_jiasha"))
                {
                command("ah");
                who->set_temp("jiasha_given",1);
                return 1;
                }
        else return notify_fail("ʲô���⣿��ϡ����\n");
}
