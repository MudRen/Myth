inherit F_VENDOR_SALE;

void create()
{
    set_name("С���", ({"huoji"}));
  set("gender", "����" );
  set("age", 18);
  set("per", 25);
    set("combat_exp", 100000);
    set("max_kee", 600);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
set_skill("force",100);
set_skill("wuxiangforce",100);
set_skill("dodge",100);
set_skill("jindouyun",100);
set_skill("puti-zhi",100);
set_skill("unarmed",100);
set_skill("parry",100);
map_skill("force","wuxiangforce");
map_skill("unarmed","puti-zhi");
map_skill("dodge","jindouyun");
set("force",1500);
set("max_force",1500);
set("force_factor",50);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
        object ob;
  ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
                "С��ư�����һ�ۣ����Թ��Ե�æ����Ļ�ơ�\n",
                "С������˰Ѵ�ɨ��ɨ��¥������\n",
                "С�����Ĩ�����˲������Ļҳ���\n",
                "С��Ʋ��˲���ͷ�ϵĺ�ˮ��\n",
        }) );
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
        add_action("do_vendor_list", "list");
          add_action("do_cast", "cast");
}
int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();
  message_vision("$N����$n���Ͱ͵��������ȴ��ôҲ�Ų����졣\n",who,me);
    return 1;
}
  void greeting(object ob)
  {
if (ob->query("combat_exp")<100000)
      command("say ���������æ��û���±������ﵷ�ң�");
  if (ob->query("combat_exp")>=100000)
    command("say ��λ" + RANK_D->query_respect(ob) +"ʧ��ʧ����");
}
