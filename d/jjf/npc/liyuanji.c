// ��� npc: /d/jjf/npc/lijiancheng.c
// created 5-20-97 pickle
 
inherit NPC;
string expell_me(object me);
 
void create()
{
  set_name("��Ԫ��", ({"li yuanji", "li", "yuanji", "liyuanji", "jianwang", "jian wang", "wang", "jian"}));
  set ("long", @LONG
��Ԫ�������Ƹ�����Ԩ�����ӣ��ܷ⽨��������������Ԫ����
Ϊ���á�������һ�����������޶�������������ذ���Ϊ�ء�
������սʱ��ʧ��Ҫ�ݵ㣬ʵ��������Ϊͷʹ��
LONG);
 
  set("title", "����");
  set("gender", "����");
  set("age", 22);
  set("str", 40);
  set("per", 15);
  set("int", 20);
  set("cps", 50);
  set("cor", 50);
  set("combat_exp", 300000);
  set_skill("blade", 50);
  set_skill("force", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("yanxing-steps", 50);
  set_skill("wuhu-blade", 100);
  set_skill("lengquan-force", 50);
  set_skill("unarmed", 50);
  set_skill("changquan", 100);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("blade", "wuhu-blade");
  map_skill("parry", "wuhu-blade");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 150);
  set("max_kee", 700);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", 50);

  setup();
  carry_object("/d/jjf/obj/lingjian-jian.c"); 
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  string myrude=RANK_D->query_rude(me), player=me->query("id");
  int kar=(int)me->query_kar();

  if ((string)me->query("family/family_name") == "������")
    {
      command("say ���"+myrude+"��������̫��үͷ�϶�����");
      command("kill "+player);
      return 1;
    }
  if (random(kar-10) > 10)
   {
     command("sneer "+player);
     command("say ���ӽ���û���£����"+myrude+"������ҹ���");
     me->move("/d/jjf/zuixing");
     return notify_fail("�ҿ��������ã����򡣡���\n");
   }
  command("say ������ƽ�ɱ�ˣ��������㵹ù��");
  command("kill "+player);
  return 1;
}
