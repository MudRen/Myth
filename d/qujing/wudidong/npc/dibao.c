// dibao.c

inherit NPC;

string ask_for_rumors();
string reply_about_monks();
void create()
{
  set_name("�ŵܱ�",({"zhang dibao","zhang","dibao"}));
  set("title","�ر�");
  set("gender", "����");
  set("age", 40);
  set("long","�ŵر��ĵ����ƺ�����ʱ��֪��Ҫ���ر�������ȡ����ô�������֡�\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "friendly");
  set("inquiry", ([
		   "name" : "�������ţ���Ϊ����ر���",
		   "here" : "�������Ŵ���������š�",
		   "rumors" : (: reply_about_monks :),
		   "����" : "Ҳ��֪��λ��Ӣ���б��°�����ȳ�����ȫ�����������춼���Ļ̵̻ġ�",
		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
string reply_about_monks()
{
  command("say ��˵�����С���ֹ��ˣ�Ҳ��֪����ô���¡�");
  return ("���������˵������Ū��ô�������ⲻ�������ɶ���ץȥ�ˡ�");
}
string ask_for_rumors()
{
  command("say ������������Щ������������ȥ����֪�᲻����̣ׯ�ڡ�");
  return "�������ż��ֳ����£���˵��ͷ���������������ˡ�����";
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  say("�ر�˵������λ" + RANK_D->query_respect(ob)+"����ӭ�����żҴ壡\n");
}
