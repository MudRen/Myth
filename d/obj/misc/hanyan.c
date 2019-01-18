//Cracked by Roath
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

inherit STICK;

void create()
{
  set_name(HIB "����ǹ" NOR, ({ "hanyan qiang","hanyan", "qiang"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","һ����������ʽ����ǹ��\n");
    set("unit", "��");
    set("wield_msg", "$N�ó�$n�������ϣ����۽�$n���š�\n");
    set("unwield_msg", "$N��$n�ȵ�һ�ã����뻳�\n");
  }
  init_stick(2);
  setup();
}

void init ()
{
  add_action ("do_smoke", "smoke");
}

int do_smoke (string arg)
{
  object me = this_player();
  object ob = this_object();
  string msg;

  if (! arg || this_object() != present (arg, me))
    return 0;

  switch (random(5))
  {
    case 0:
      { msg = "$N����$n������������һ�ڡ�\n"; break; }
    case 1:
      { msg = "$N����$n����һ���̡�\n"; break; }
    case 2:
      { msg = "$N����ü��ͷ��$n������һ�ں��̡�\n"; break; }
    case 3:
      { msg = "$Nһ�߳�˼һ������$n���˿��̡�\n"; break; }
    case 4:
      { msg = "$N�Ե��ͷ����$n������һ����\n"; break; }
  }
  message_vision (msg,me,ob);
  remove_call_out ("smoke_spreads");
  call_out ("smoke_spreads",random(3)+3,me,ob);
  return 1;
}

int smoke_spreads (object me, object ob)
{
  string msg;
  switch (random(5))
  {
    case 0:
      { msg = "�̴�$N�ıǿ�����������ڿ���ɢ����\n"; break; }
    case 1:
      { msg = "һ����Ȧ��$N���������˳�����\n"; break; }
    case 2:
      { msg = "���������ڿ�����ɢ����\n"; break; }
    case 3:
      { msg = "������Ʈ����\n"; break; }
    case 4:
      { msg = "��Χɢ���ŵ�������ζ��\n"; break; }
  }
  message_vision (msg,me,ob);
  if (random(4) == 0)
    return 1;
  remove_call_out ("smoke_spreads");
//  call_out ("smoke_spreads",random(3)+3,me,ob);
  return 1;
}


