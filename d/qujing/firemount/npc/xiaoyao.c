// created by snowcat on 4/12/1997

inherit NPC;

void create()
{
  set_name("С��", ({"xiao yao","yao"}));
  set("gender", "����");
  set("age", 10);
  set("long","һ����ü���۵�С������\n");
  set("combat_exp", 10000);
  set("daoxing", 10000);

  set("per", 15);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("unarmed", 40);
  set("max_sen",200);
  set("max_gee",200);
  set("max_gin",200);
  set("force",300);
  set("max_force",300);
  set("max_mana",300);
  set("force_factor",5);
  set_skill("spells",10);
  set_skill("stick",10);
  set("chat_chance",2);
  set("chat_msg",({
        "С����һ��С��ü��\n",
        "С��ƴ����գգһ�����������С���ۡ�\n",
        "С��һ������ߴһ��ˤ�ڵ��ϡ�\n",
        "С���ߵ�����ǰ����ѽ�ް����˼�����\n",
        "С��ವ�һ����˦�ֵ����ڶ����ϡ�\n",
        "С��һ��С�ģ�ѽѽѽ�Ӷ�����ʧ�ֵ�������\n",
    }));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();

}
�