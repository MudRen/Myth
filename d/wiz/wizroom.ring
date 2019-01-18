// Room: /d/wiz/wizroom.c
// ��ʦ���߷��䣬����д��Ȩ�ޡ�����

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","��ʦ������");
set("long",
@LONG

   wizroom ת��/adm/npc/wizroom.c
   wizroom ת��/adm/npc/wizroom.c
   wizroom ת��/adm/npc/wizroom.c
   wizroom ת��/adm/npc/wizroom.c
   wizroom ת��/adm/npc/wizroom.c

������������񻰵���߻������ģ����µĵ�ɢ������͵Ĺ⣬��ľ
��̨����Χ���˼������ӡ���������Ĳ�������ô�ĺ�г���������
����������飬ʹʹ���ؽ����е�ʵ��ʹ�ҷ���ƽʱ��ʦ�Ƕ�
�������ͷ�������Ϸ������ʲô�ش����飬ͨ��Ҳ�����������ġ�
LONG
); 

  set("exits", ([ /* sizeof() == 2 */
/*
  "west" : __DIR__"system",
  "up" : __DIR__"wizroom1",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"jail",
  "kz": "/d/city/kezhan",
*/
  "down": WIZARD_ROOM,
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
          add_action("say_log",({ "say","'"}));
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 1;
       if (verb=="quit") return 1;
       if (verb=="look") return 1;
       return 1;
}

int say_log(string msg)
{
        object me;
        me = this_player();
        if( !msg ) return 0;
        else
        "/cmds/std/say.c"->main(me, msg);
        MONITOR_D->mudring_log("wizsay", me, msg);
        return 1;
}

