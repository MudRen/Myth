// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#define NAME "��¶������"

inherit NECK;

void create()
{
  set_name(HIB NAME NOR, ({ "icedew lace", "icedew" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","һ��͸���ı�¶��������Ϊ���������䱦��\n");
    set("unit", "��");
    set("material", "icedew");
    set("armor_prop/armor", 1);
  }
  set("no_drop", "���Ǹ���ֵ���ǵ��鱦��������㶪���ء�\n");
  set("no_give", "���Ǹ���ֵ���ǵ��鱦��������㶪���ء�\n");
  set("no_sell", "���Ǹ���ֵ���ǵ��鱦��������㶪���ء�\n");
  set("is_monitored",1);
  setup();
  call_out ("autodestruct",60);
}

void init ()
{
  add_action ("do_wear", "wear");
}

void autodestruct ()
{
  object lace = this_object();
  object where = this_player();
  if (! where)
    where = environment (lace);

  if(where)   //mon 8/14/97
    message_vision ("ֻ��"+NAME+"�ڻ�Ϊһ����������ˮ�鲻���ˡ�\n",where);
  destruct (lace);
}

void disappear_fail (object me)
{
  object lace;
  lace = present("icedew lace",me);

  if (!lace)
    lace = present("icedew lace",environment(me));
  
  if (!lace)
    return;
  
  message_vision ("ֻ��"+NAME+"��$N�����ڻ�Ϊһ����������ˮ�飬"+
                  "���ڵ��ϲ����ˡ�\n",me);
  tell_object (me,"���ϧ��\n");
  
  destruct (lace);
}

void disappear_success (object me)
{
  string dir;
  object queen;
  object lace;
  lace = present("icedew lace",me);

  if (!lace)
    lace = present("icedew lace",environment(me));

  if (!lace)
    return;

  message_vision ("$N����һ��"+NAME+"��\n"+
                  "ֻ��"+NAME+"���һ����ɫ����⣬Χ��$N�����˼�Ȧ"+
                  "ֱ������б�ɶ�ȥ��\n",me);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  queen = new (dir+"npc/queen");
  queen->announce_success (me,"�ҵ���"+NAME);
  destruct (queen);
  destruct (lace);
}

int do_wear (string arg)
{
  string dir;
  object queen;
  object me;
  me = this_player();

  if (arg != "icedew lace" &&
      arg != "icedew" &&
      arg != "all")
    return 0; // wearing something else

  if (me->query("obstacle/nuerguo") == "done")
  {
/*
    dir = __DIR__;
    dir[strlen(dir)-4] = 0;
*/
    dir = "/d/qujing/nuerguo/";
    queen = new (dir+"npc/queen");
    queen->refuse_player (me);
    destruct (queen);
    disappear_fail (me); 
    return 1;
  }  

  if (me->query("obstacle/nuerguo") == "stomachache")
  {
    disappear_fail (me);
    return 1;
  }  

  if (me->query("combat_exp")<2000)
  {
    disappear_fail (me);
    return 1;
  }  

  if (random(5) == 0)
    disappear_success (me);
  else
    disappear_fail (me); 
 
  return 1;
}
