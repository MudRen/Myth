inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","ǰ Ժ");
  set ("long", @LONG
        ����  �� �� ��  ����
�����ǡ����Źȡ�����̳��Ժ��Ժ�������˻����ݲݣ��괺���ڣ���
ïʢ���ʻ��ٿ���ɷ�ǲ��á�Ժ����һ�·�ˮǽ�������ǵķ���ϰ��
����˵���Ե�ɷ��а��ǽ�������һ�������š��֡�

LONG);

  set("exits",([ "northup" : __DIR__"juyitang", ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}