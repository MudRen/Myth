
//xiaowu.c Ѱ����ң
inherit ROOM;
int do_open(string arg);
void create()
{
        set("short", "Сé��");
        set("long", @LONG
����һ����ª��Сé�ݣ�����ǽ�Ϲ���һ���������������˵���Ҳ��߳����ơ�
����ǽ������һ��ʫ��
        ���鵺�ϱ��죬���й��������ߡ�
        һ��������ˮ�棬Ը��ʰ��ϧ������
LONG
        );
   set("exits", ([
      "out" : __DIR__"shangu2",
   ]));
      set("objects", ([
      __DIR__"npc/servent" : 1,
   ]));
   setup();
}
void init()
{
 add_action("do_open","open");
}
int do_open(string arg)
{
 object who=this_player();
 object ob;

 if(who->is_busy()) return notify_fail("����æ���أ�\n");
 if(!arg || arg != "�ܵ�")
           return notify_fail("��Ҫ��ʲô��\n");
 if( (int) who->query("force_factor") >= 100 )
 {
  write("���������һ�Ȱ��š�\n");
         if( !query("exits/west") ) {
       set("exits/west", __DIR__"xiaowu2");
         call_out("close_path", 5);
      }
  return 1;
 }
 else
 {
  write("����������ǽ����û��ʲô������\n");
  return 1;
 }
}
int valid_leave(object me, string dir)
{
        object ob;
        int i;
if( dir == "west" && ob=present("servent", this_object()))
 {
 message_vision("$N��$n�ȵ������ȥ����������˵����\n", ob,me);
 ob->kill_ob(me);
 return notify_fail("���ӣ�\n");
 }
 else
  return 1;
}
void close_path()
{
        if( !query("exits/west") ) return;
        message("vision","�����ֿ���һ�������ˡ�\n",this_object() );
        delete("exits/west");
}
