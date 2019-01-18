// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "���չ�");
  set ("long", @LONG

���߽���һ��յ����Ĺ��ֻ������վ�����޺�����ÿһ���޺���
����ŭĿ���ӣ����ŵĶ㵽���˷��Ƶĵ������棬��ͻȻ����������
������һ����ť�������Ű���һ�£�ͻȻ�����һ�գ�ԭ���Ǹ��ݾ���
������һ�ƣ�������ϲ��ԭ��������ˮ������ͨһ������ˮ�У�����
���ϰ����������Ⱦ�ʹ�����ͷһ������ŵĻ��˹�ȥ��ԭ��һ��Ѫ
����֪��������������ȣ����㶤���˺��С�����֮�������������
ʲ�ᡣ��������һ����Ȼ��һ������ͷ��ͻȻ������ͷ�����һƬ��
�ǣ�����Ĳ�������Ķ�ͷ������һ�����������˹�����ȫ���亹��

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"     : __DIR__"loujingong",
  "southeast" : __DIR__"kuimugong",
  "northeast" : __DIR__"weitugong",

]));


  set("objects", 
      ([
       __DIR__"stars/lfy" : 1,
      ]));


  setup();
}
 
