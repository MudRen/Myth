  inherit NPC;

void create()
{
        set_name("����", ({"hou yi"}));
  set("gender", "����" );
    set("title","�������");
        set("long", "�����Ǵ�˵������Ÿ�̫���Ĵ�Ӣ�ۡ�\n");
    set("age", 25);
  set("per", 25);
      set("combat_exp", 500000);
        set("daoxing", 50000);
      set("max_kee", 900);
    set("max_sen", 500);
  set("attitude", "friendly");
    set("per", 30);
  set_skill("force",180);
set_skill("archery",200);
  set_skill("dodge",180);
  set_skill("unarmed",180);
    set_skill("baihua-zhang",180);
  set_skill("parry",180);
map_skill("unarmed","baihua-zhang");
set("force",1500);
set("max_force",1500);
set("force_factor",50);
  setup();
    carry_object("/d/obj/cloth/surcoat")->wear();
      carry_object("/d/obj/weapon/archery/zhentian-arrow");
}
void init()
{
        object ob;
  ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
                  "�������쳤̾��\n",
                    "������˲���ͷ�ϵĺ�ˮ��\n",
                  "����������¶��һ˿��Թ��\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                  "name" : "�Ҿ������յĺ��ࡣ\n",
         ]) );
add_action("do_cast","cast");
}
int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();
  message_vision("$N����$n���Ͱ͵��������ȴ��ôҲ�Ų����졣\n",who,me);
    return 1;
}
