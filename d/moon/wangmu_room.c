//Cracked by Roath
#include <ansi.h>
inherit ROOM;
int block_cmd(string); 

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�˼�������ĸ�Ӵ�����ʰ����𴦲�ͬ�����ֲ���������ġ�������ǵ�
������ľ�壬�����ư��𡹣����꺮���ѡ�����ɽˮ�������ë��
�ܣ��򼯽����򲩹ţ��������٣����ֻ����������ֵ��Σ��������Ƕ
���ġ�һ��һ�����������鴦�����趦�������ñ��⴦���򹩻���ƿ��
���辰��������ʽ����������Բ�ط����������Ҷ����������ڣ�����
���Ž��أ���͸���硣
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiwangmu.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huilang1.c",
]));
    set("no_fight",1);
  set("no_magic", 1);   

  setup();
}

void init() 
{
  add_action("block_cmd", "", 1); 
}

int block_cmd(string args) 
{
  string verb; 
  verb = query_verb(); 
  if (verb == "bian") return 1;
  if (verb == "cast") return 1; 
  return 0; 
}
