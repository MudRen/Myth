//created 6-9-97 pickle
//�ױ�
 
inherit NPC;

void create()
{
  set_name("�ױ�", ({"qin bing", "qin", "bing", "soldier", "qinbing"}));
  set ("long", @LONG
һ�����δ󺺣��������·�������븮���ױ���������ɵĽ�������
LONG); 
  set("title", "������");
  set("gender", "����");
  set("age", 25);
  set("combat_exp", 80000);
  set_skill("blade", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("wuhu-blade", 60);
  map_skill("blade", "wuhu-blade");
  set("max_sen", 200);
  set("max_kee", 300);
  set("chat_chance", 7);
  set("inquiry", ([
        "name" : "��ʲô�ʣ������۾����ῴ�ģ�",
        "here" : "�����������¥����Ŀɱȶ������Ʒ���ǿ�ö�����",
        "rumors" : " ��˵�����������ӣ��ߣ�",
        "����" : "�ߣ����ǰ����Ӵ��ˣ�����˭Ҳ�����������Ұ��",
         ]) );
  setup();
 
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}
int accept_object(object me, object ob)
{
  object npc=this_object();
 
  if ((string)ob->query("name_recognized")!="�븮���")
    {
      command ("say ��������������˻����ˣ�");
      call_out("destroy", 1, ob);
      return 1;
    }
  call_out("leavehere", 2, npc, me);
  return 1;
}
void leavehere(object npc, object me)
{
  command("ah");
  command("say ��Ȼ�����м��£������ȥ�죡");
  command("thank "+me->query("id"));
  command("go northwest");
  destruct(npc);
  return;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}







