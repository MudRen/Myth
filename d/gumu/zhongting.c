#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIC"��Ĺ����"NOR);
  set ("long", @LONG


������Ĺ�ĵڶ���ʯ�ң����������Եúܿտ���һ��
ʯ��������ʯ�Σ�̧ͷ�ܿ���һ������(bian)����֮
�����һ�


LONG);


  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"houting",
  "west" : __DIR__"armorroom",
  "east" : __DIR__"weaponroom",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "
          ��ԯ��Ĺ  ��������
",
]));

        call_other("/obj/board/gumu_ss", "???"); 
  setup();
}
void init()
{
  add_action("do_jump", "jump");
}
int do_jump(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("��Ҫ�������\n");
  if(arg=="bianhou")
    return notify_fail("������������\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="paibian")
    {
      message_vision(HIY "$Nʹ��һ�������ײ���컨���ϣ�\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "�ڹ�Ĺ���е������Լ�ײǽ���ˣ�\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(YEL "$N������ǰһƬģ����������ð��\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N���˵������һ��,ƽ�ȵ���������֮��\n", me);
      me->move(__DIR__"bianhou");
      return 1;
    }
}

