// ��� npc: /d/jjf/npc/lijiancheng.c
// created 5-20-97 pickle
 
inherit NPC;
string expell_me(object me);
 
void create()
{
  set_name("���", ({"li jiancheng", "li", "jiancheng", "lijiancheng", "qiwang", "qi wang", "wang", "qi"}));
  set ("long", @LONG
��������Ƹ�����Ԩ�Ĵ���ӣ��ܷ������������������ս
ʱ����ս�������޶����������Ժգ���Ҳ��������Ԫ��һ����
�԰��̡�
LONG);
 
  set("title", "����");
  set("gender", "����");
  set("age", 36);
  set("str", 25);
  set("per", 25);
  set("int", 25);
  set("combat_exp", 250000);
  set_skill("spear", 100);
  set_skill("force", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("yanxing-steps", 60);
  set_skill("bawang-qiang", 60);
  set_skill("lengquan-force", 60);
  set_skill("unarmed", 100);
  set_skill("changquan", 60);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 200);
  set("max_kee", 600);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 30);

  setup();
  carry_object("/d/jjf/obj/lingjian-qi.c"); 
  carry_object("/d/obj/weapon/spear/tiespear")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  string myrude=RANK_D->query_rude(me), player=me->query("id");
  int kar=(int)me->query_kar();

  if ((string)me->query("family/family_name") == "������")
    {
      command("say ������޵ľ��ǽ��������ӣ����"+myrude+"��Ȼ�Լ�����������");
      command("emote �������ɱ���ǲ�ɱ��");
      if (random(kar-10) > 10)
       {
         command("sneer "+player);
         command("say ���ӽ�������ã����"+myrude+"������ҹ���");
         me->move("/d/jjf/zuixing");
         return notify_fail("�ҿ��������ã����򡣡���\n");
       }
      command("emote �ȵ���ɱ��");
      command("kill "+player);
      return 1;
    }
    command("say �������飬����������������ô�죿\n");
  return 0;
}
