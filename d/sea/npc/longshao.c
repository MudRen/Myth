// Changed by sjmao  09-11-97
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("����ү", ({"long shaoye","shaoye","taizi","long","prince"}));

set("long","�����Ĵ���ү��\n");
       set("gender", "����");
	set("int", 25);
       set("age", 26);
       set("title", "����̫��");
       set("attitude", "peaceful");
       set("combat_exp", 450000);
  set("daoxing", 300000);

       set("rank_info/respect", "����");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set_skill("literate", 50);
       set_skill("unarmed", 120);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("fork", 80);
       set_skill("spells", 80);
        set_skill("seashentong", 80);
        set_skill("dragonfight", 120);
        set_skill("dragonforce", 80);
        set_skill("fengbo-cha", 80);
        set_skill("dragonstep", 80);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "�빬": (: expell_me :),
                "leave": (: expell_me :), ]) );


      create_family("��������", 2, "ˮ��");
	setup();

        carry_object("/d/ourhome/obj/choupao")->wear();
        carry_object("/d/obj/weapon/fork/gangcha.c")->wield();
}

void attempt_apprentice(object ob)
{
        command("look " + ob->query("id"));
        if ( (string)ob->query("gender")=="����"){
           command("kick " + ob->query("id"));
           command("say ��û������㣡\n");
           return;
        }

        command("sister " + ob->query("id"));
        command("recruit " + ob->query("id") );
        command("say �ٺ٣�ֻҪ" + RANK_D->query_respect(ob) +
"��ʦ����Ū�����ˣ������ٻ��������ܲ�����\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="��������")
    {
        if ( (string)me->query("gender")=="����"){
           command("slap " + me->query("id"));
           return("��ʲô�£�Ҫ����ȥ�����Ǽ���ͷ�ӣ�\n");
        }

      message_vision("����ү��������������$N�����������ס$N���������˻�����\n", me);
      return ("��ȥ���Ҹ����ɡ���������ô֪����\n");
    }
  return ("��֪����\n");
}
�
