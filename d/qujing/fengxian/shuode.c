// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "˶����");
  set ("long", @LONG

˶��������������ɫ����������ܰ�����ݻ�̳��������һ��
̫ʦ�Σ�ǽ����һ����Ƥ�����Ρ��������ǿ�����ϢƷ���ר
�����������ԽӴ��������ܵĳ�����
    
LONG);

  set("exits", ([
        "northwest"    : __DIR__"shang",
        "southwest"    : __DIR__"junhou",
      ]));
  setup();
}

