// Room: �׹Ƕ�,�׹Ǿ���ס��  
//create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "�׹Ƕ���");
  set ("long", @LONG

    ���������÷��˰׹Ǿ���Ϣ�ĵط�����ɭɭ�ģ��춥��
�����յĵ���һЩˮ�����������������ϣ�����һĨ��һ
��Ѫ��ζֱ����ӣ���֪��Ѫ����ˮ��
        
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "out" : __DIR__"dongnei",
  ]));

  set("objects",([
        __DIR__"npc/baigujing":1,
        __DIR__"npc/kuloubing":2,
                ]));

  set("outdoors", __DIR__"");                   

  setup();
}
