#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_DAMAGE;

string inputstr,verb;

int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());

set("long",@LONG
    ����һ�������ħ�����ǣ������ɾ�ǧ�Űپ�ʮ�ſ����˵�������ƶ��ɣ�������

    ����<help star>�Ի�ø����ħ����

LONG
);

  set("unit","��");
  set("value", 10000);
  set("material", "ring");
  set("armor_prop/armor", 100);
  set("armor_type", "cape");
  set("light",1);
  set("unequip_msg","$N����������ժ����������\n");
  set("wear_msg", "$N���ϡ�����˼�ˣ���������������˼����ˮ��\n");
  set("no_give","��ô���֮��������ת�����ˣ�\n");
  set("no_drop","��ô���֮����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  setup();
}
void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "�ġ��", ({ "my star", "star" }));
  else
    set_name ("���", ({ "my star", "star" }));

   add_action("help","help");
   add_action ("do_wakeup", "wakeup");
   add_action("full","full");
  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="star") return 0;

write(@Help
    
    �����ʹ�����µ�����:
       
       wakeup <���>                    <�ѻ��Բ��ѵ���ҽ���>
       full <���>                      <ȫҽ, ��������������ڶ�Ϊ�Լ�>
       
          ע���������ֻ����ʹ�����Σ��������κ�����ʧȥ��ԭ�е�ħ����

Help

);

  return 1;
}


int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));
    if(me->query("id")!="gigi")
return notify_fail("�����������Ǵ���͵���ģ�\n");
    if(query("used") >= 6)
          return notify_fail("��ֻ�����Ѿ��ù������ˣ������Ȼ��ɫ��\n");

  if (!me) return notify_fail ("[star]: full error: �Ҳ���"+str+"\n");
max=me->query("max_sen");
me->set("eff_sen", max);
me->set("sen", max);
max=me->query("max_gin");
me->set("force", me->query("max_force"));
me->set("eff_gin", max);
me->set("mana", me->query("max_mana"));
me->set("atman", me->query("max_atman"));
me->set("gin", max);
max=me->query("max_kee");
me->set("eff_kee", max);
me->set("kee", max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();
  add("used", 1);

  message_vision( "$N������һ�Ź��̵�������,"+me->query("name")+"��ȫ������Ѹ�ٻָ��ˡ�\n",this_player());

  return 1;
}

int do_wakeup (string str)
{
  object me,who;
  me=this_player();
  if (!str) return notify_fail ("[star]: wakeup error, wakeup <someone>\n");
  if(me->query("id")!="gigi")
return notify_fail("�����������Ǵ���͵���ģ�\n");
  if(query("used") >= 6)
          return notify_fail("��ֻ�����Ѿ��ù������ˣ������Ȼ��ɫ����\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, û��"+str+"\n");
   message_vision( "$N����һ����˼֮������ĵ�������$n�����ӡ�\n"+
   "$n�����ָ���֪����\n",me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  add("used", 1);

  return 1;
}

