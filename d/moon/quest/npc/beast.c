//Cracked by Roath


inherit NPC;

void create()
{

string* name=({"����","���","��Ӥ","���","����","����"});
string* desc=({"�������㣬��ͷ��צ�������ţ������ͨ�졣\n",
               "��ͷ����Ĺ�����ﳤ��һ֧�������ߵķ������ݡ�\n",
               "���ž�ֻ�Դ��Ĺ��ޣ�������������Ӥ����ޡ�\n",
               "�����������׺���������Ϊʳ�����֮�����������ݣ�����������\n",
               "һ����������ͷ���������ɣ��ſ���ڣ���������\n",
               "һͷ˶���ޱȵ�Ұ������ë��צ�����������\n"});
int r=random(6);
  set_name(name[r],({"monster"}));
  set("long",desc[r]);
  set("age", random(900)+100);

  set("daoxing", 1200000);
  set("combat_exp", 10000);
  set("attitude", "friendly");
  set_weight(1000000000);
  set("per",9);
  set("max_kee", 1000);
  set("kee",1000);
  set("sen",2000);
  set("max_sen", 2000);
  set("max_force", 500);
  set("force", 500);
  set("force_factor", 20);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 100);


  set_skill("spells", 180);
  set_skill("dao", 180);
  
  set_skill("dodge", 50);
  set_skill("parry", 50);
  map_skill("spells", "dao");
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
        (: cast_spell, "thunder" :),
  }));


    setup();
}
varargs int receive_damage(string type, int damage, object who) {
  if (type=="kee") return 1;
  return ::receive_damage(type,damage,who);
}
varargs int receive_wound(string type,int damage,object who) {
  if (type=="kee") return 1;
  return ::receive_damage(type,damage,who);
}
  



