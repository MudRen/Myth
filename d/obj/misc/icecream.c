// created by snowcat

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
  set_name("�����", ({ "ice cream" }) );
  set_weight(350);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һ�б���ܡ�\n");
    set("unit", "��");
    set("food_remaining", 10);
    set("food_supply", 10);
  }
  init_hammer(1);
  setup();
}

int init ()  
{   
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_setunit", "setunit");
  add_action ("do_eat", "eat");
  return 1;
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
    return 0;
  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("name",arg);
  this_object()->set("long","һ"+this_object()->query("unit")+arg+"��\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","һ"+arg+this_object()->query("name")+"��\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_eat (string arg)
{
  string *hows = ({
    "����Ҹ���",
    "��������",
    "��������",
    "�����̵�",
    "��Ϊ�����",
    "��ͷ������",
    "�м����ܵ�",
    "������",
    "�����û��������",
    "ׯ�ϵؿ��Ŵ�ң�Ȼ���¸ҵ�",
    "���������",
    "����������",
    "�������ɵ�",
    "�������ۣ�",
    "ҡͷ���Ե�",
    "����һЦ��",
    "����һ��",
    "���ֱ��ŵ�",
    "��ͷ���Ե�",
    "������Ц����������",
    "�ƿ����ˣ��ںü�ʽ��",
    "��ͷ�����",
    "�˷ܵ���ͷ�󺹣�",
    "��Ƽ��ݵ�",
    "Ĩȥ�۽ǵ��Ứ��",
    "����֣�һ��ţ�",
    "������צ��",
    "ʮ��ǫ���",
    "�ߵ�����ͨ�죬",
  });

  string *manners = ({
    "��$n�������ﷴ�����˼��£�",
    "��$n�ڵ��Ϸ��ض�⣬",
    "��$n��ǽ���ص�һ���ҿ���",
    "��$n���Ŀ���ϸů��һ�£�",
    "��$n���͹���Ѹ��һը��Ȼ��",
    "������$n��",
    "ʹ��˺��$n��һ��һ���",
    "��$n������Ĩ��һ�����ެ�ѽ���",
    "����$nպ�ź��ĺ��ǣ�",
    "��$n������һ����Σ�",
    "��$n���������Ƭ��ƹϣ�",
    "��$n�ڽ�����һպ��Ʒ��ζ",
    "��$n�����������һ�㣬���е�",
    "��$n�ڿ�ˮ��һ�ݣ�����",
    "��$n�ڻ���һ�ǣ��Ͻ�",
    "��һ�������п�$n��",
    "��������$n",
    "��һ�����˾�����$n�ϣ�",
    "��$n������ˮϴ�øɸɾ�����",
    "��$n�����˰��죬",
    "��$n����һ��ե��˿��",
    "��$n�Ϲ�һ��������ң�",
    "��$n�ʹн���ĩ����һ��",
    "��$n���飬�������ˣ�",
    "��$n�г�С�飬���ϼ����������ȵ����͹��ﳴ�ɹ���$n��",
    "��$n�Ž�������Ͻ��ͺ���С�����ɺ���$n��",
    "��$n�����ڹ��ﵹ�������ͳ�һ���Ǵ�$n��",
  });

  string *actions = ({
    "�ſ�ӣ��С��������ȥ",
    "����Ƭ���촽ҧסֻһ����������ȥ",
    "һ�����������ȥ",
    "��������ƹƹ����һ��",
    "����üͷʹ�ļ��׵س�����ȥ",
    "������һ�ӣ�������Ӱȵ�һ����ס",
    "���������ʹ����һ��",
    "Ӳ��ͷƤ����׽���س�����ȥ",
    "��ર����ü���۵س�����ȥ",
    "�������������ݱ�������ڵ�������ȥ",
    "������ζ����ָ��������ȥ",
    "����û�����첱�ڽŵ�������ȥ",
    "�ʷʵ�����һ��",
    "��������Ͳ����������˶���",
    "һ���ҧ�ų��˲�����",
    "�ſ�Ѫ���ڣ�������������һ��",
    "�Ե��񾭴�����ð����",
    "�Ե������񶫵�����",
    "�Ե������������",
    "�Ե����ߵ��������",
    "�Ե÷����������ذ�",
    "���̻��ʵط�����������ҽ�������ȥ",
    "��������ش����������ֻһ�����������������������ȥ",
    "ʹ�಻���س�����ȥ",
  });

  if (arg != this_object()->query("id"))
    return 0;

  message_vision ("$N"+rdm(hows)+rdm(manners)+rdm(actions)+"��\n",
                  this_player(),this_object());
  this_player()->set("food", (int)this_player()->max_food_capacity());
  this_player()->set("water", (int)this_player()->max_water_capacity());
  destruct(this_object());
  return 1;
}

