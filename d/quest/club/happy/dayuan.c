inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","ǰ Ժ");
  set ("long", @LONG
          ����    ��  ��  ��  ��  ��    ����

�����ǡ��λش��Ƹ󡽵���̳��Ժ��Ժ�������˻��ݣ��괺���ڣ���
ïʢ���ʻ��ٿ���ɷ�ǲ��á�Ժ����һ�·�ˮǽ�������ǵķ���ϰ��
����˵���Ե�ɷ��а��ǽ��д���������֡��顽 ��������


LONG);

set("exits",([ 
"northup" : __DIR__"juyitang",
"east" : "/u/lost/work",
]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}
     int valid_leave(object me, string dir) 
{

if( dir=="east" && me->query("id")!="passion")
return notify_fail("�����㲻��ȥ!\n");
return ::valid_leave(me, dir); 

}
