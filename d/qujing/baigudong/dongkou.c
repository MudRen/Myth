// create by smile 12/8/1998
// �׹Ƕ����׹Ǿ�����Ϣ��
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�׹Ƕ�");
  set ("long", @LONG
   [1;37m
        $$$                  $$$$$$$$$$$ 
       $ $                   $$       $$           $$$    $$$$$$$$$$$$$$$
      $ $                    $$$$$$   $$            $ $   $$$$$$$$$$$$$$$
     $ $$$$$$$$$$$$$         $$  $$   $$             $$$  $ $         $ $
     $ $$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$             $ $  $$$$$  $ $
     $ $         $ $     $$                $$       $$$   $ $  $$$$$  $ $
     $ $$$$$$$$$$$ $         $$$$$$$$$$$$            $ $  $ $         $ $
     $ $$$$$$$$$$$ $         $ $      $ $             $$$ $ $ $$$$$$$ $ $
     $ $         $ $         $ $$$$$$$$ $                 $ $ $ $ $ $ $ $
     $ $$$$$$$$$$$ $         $ $      $ $             $$$ $ $ $ $$$ $ $ $
     $$$$$$$$$$$$$$$         $ $$$$$$$$ $            $ $  $ $ $$$$$$$ $ $
                             $$$     $$$$           $$$   $$$       $-$ $
                                                          $$$        $$$$
[2;37;0m
      �������������ð�ź��̣����Ʈ��������ζ��Ѭ����ֱ��Ż�¡����ű���
    ���ż������ã������һЩ�����������Ե��Ĺ������˵����������к���
    
LONG);

  set("exits", ([
        "southdown"   : __DIR__"dongting",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
  add_action("do_enter","enter");
}

int do_enter(string arg)  //enter baigudong,must dx>100y,and mana>1800
{
    object me;
  if(!arg) return notify_fail("�����ʲô��\n");  
  if(arg!="dong"&&arg!="hole"&&arg!="��"&&arg!="�׹Ƕ�")
      return notify_fail("�����ʲô��\n");  

      me = this_player();
   message_vision("[1;33m$N������һ��������ס���ӣ����׹Ƕ����˹�ȥ��[2;37;0m\n",me);
   if(me->query("obstacle/baigudong")!="done")
    {
   if(me->query_temp("obstacle/baigudong_yao_killed")!="done"||
      me->query("combat_exp")<100000||me->query("max_mana")<1800)
     {
       message_vision("[1;31m$N�嵽���ڣ�ͻȻһ����̹���,������һ��Ѭ��������\n$N����һ�����赹�ڵ���!\n[2;37;0m",me);
       me->unconcious();
       return 1;
     }
    };
   message_vision("[1;35m���Ƶĺ���һ����$N����ʱ��ɢ��ȥ\n[1;36m$Nһ��̤���׹Ƕ�![2;37;0m\n",me);
     me->move(__DIR__"dongnei"); 
  return 1;     
}
