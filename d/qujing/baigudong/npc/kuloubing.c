//modified from pingding/npc/yao1.c 
// created by smile 12/10/1998

inherit NPC;

void create()
{
  object me=this_object();
  int i = random(9)+1;
  string str;
  set_name("���ñ�", ({"kulou bing","bing"}));
  set("gender", "����");
  set("age", 30);
  set("combat_exp", 25000*i);
  set("attitude","aggressive");
  set("per", 8);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",100*i);
  set("max_gee",100*i);
  set("max_gin",100*i);
  set("force",100*i);
  set("max_force",100*i);
  set("max_mana",100*i);
  set("force_factor",10*i);
  set("chat_chance",10);
  set("chat_msg",({
       "���ñ��ݺݵ�˵���ұ��˳��˲ű�������ģ���ҲҪ�Ա��ˣ�\n",
       "���ñ��е���������ԩ������\n",
       "���ñ����ĵ�̾��һ����������ʲôʱ������ػ�������\n",
       "���ñ��ٺ���Ц�����������������ȥ���ã�\n",
  }));

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baigudong/obj/armor")->wear();
  str = "/d/qujing/baigudong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(10);
  carry_object(str)->wield();
}
