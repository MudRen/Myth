// rewritten by snowcat on 4/12/1997
//qiaofu.c

inherit NPC;

void create()
{
  set_name("�Է�", ({"qiaofu"}));
  set("gender", "����" );
  set("age", 35);
  set("long", "����ɽ�е��Է�һ�߷�ľ��һ�ߺ���ɽ�衣\n");
  set("combat_exp", 25000);
  set("attitude", "peaceful");
  set_skill("dodge", 40);
  set_skill("axe", 50);
  set_skill("literate", 30);
  set("per", 25);
  set("max_kee", 200);
  set("max_gin", 100);
  set("max_sen", 100);
  set("chat_chance",10);
  set("chat_msg",({
        "ֻ���Է򳪵����Ƽ������Ͼ��֣����»Ĳ�·��Ѱ��\n",
        "�Է򳪵�����ɽ���������꣬�Ͻ���ʱ�ɴ��\n",
        (:random_move:)
    }));

  setup();
  carry_object("/d/ourhome/obj/linen")->wear();
  carry_object("/d/ourhome/obj/lumber_axe")->wield();
}


