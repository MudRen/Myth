//created 8-3-97 pickle
//����

inherit NPC;

string weapon_file, skill, special_skill;
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","ף","κ","��","��","��","��", "��","��","��","��","ŷ��","˾��","Ľ��","���" });
string *name_words = ({ "˳","��","��","��","��","��","��","��","־","��",
        "Т","��","��","��","��","��","��","ʢ","ʤ","��","��","��","ͬ","��",
        "��","��","��","¡","��","��","��","��","��","˼","��","��","��","ƽ",
        "��","��","ά","��","��","Ϫ","��","��","ɽ","��","��","Ȫ","��","ѷ", });
void determine_data()
{
  switch(random(5))
    {
        case 0:
        {
	    weapon_file="sword/changjian";
	    skill="sword";
	    special_skill="xiaofeng-sword";
	    break;
        }
        case 1:
        {
	    weapon_file="blade/blade";
	    skill="blade";
	    special_skill="wuhu-blade";
	    break;
        }
        case 2:
        {
	    weapon_file="mace/ironmace";
	    skill="mace";
	    special_skill="jinglei-mace";
	    break;
        }
        case 3:
        {
	    weapon_file="spear/changqiang";
	    skill="spear";
	    special_skill="bawang-qiang";
	    break;
        }
        case 4:
        {
	    weapon_file="axe/bigaxe";
	    skill="axe";
	    special_skill="sanban-axe";
	    break;
        }
    }
}
void create()
{
    string name;

    name = first_name[random(sizeof(first_name))];
    name += name_words[random(sizeof(name_words))];
    if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
  set_name(name, ({"fu jiang","fu","jiang", "general", "fujiang"}));
  set ("long", @LONG
������������ҧ��ξ�ٹ�����һ����ɳ���ϳ�������������ս��
һ���������˸��������̫ƽ�ˣ������������Է��߽��б䡣
LONG);
  determine_data();
  set("title", "����");
  set("gender", "����");
  set("age", 20+random(30));
  set("combat_exp", 300000+random(100000));
  set_skill(skill, 140);
  set_skill("dodge", 140);
  set_skill("parry", 140);
  set_skill("unarmed", 140);
  set_skill("force", 140);
  set_skill("changquan", 140);
  set_skill(special_skill, 140);
  set_skill("lengquan-force", 140);
  set_skill("yanxing-steps", 140);
  map_skill(skill, special_skill);
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  map_skill("parry", special_skill);
  set("max_sen", 400);
  set("max_kee", 700);
  set("max_force", 800);
  set("force", 1000);
  set("force_factor", 25);
  setup();
 
  carry_object("/d/obj/weapon/"+weapon_file)->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
int accept_fight(object me)
{
    command("enable dodge none");
    command("enable parry none");
    command("enable unarmed none");
    command("enable "+skill+" none");
    return 1;
}
int chat()
{
    object npc=this_object();

    if (query("sen")<query("max_sen")*20/100
      ||query("kee")<query("max_kee")*20/100)
    {
        command("enable dodge yanxing-steps");
        command("enable parry "+special_skill);
        command("enable unarmed changquan");
        command("enable "+skill+" "+special_skill);
        return 1;
    }
}
