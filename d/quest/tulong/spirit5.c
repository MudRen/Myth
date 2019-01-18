inherit ROOM; 
#include <ansi.h> 
void init();
int do_take(string arg);
int do_back(object me);

void create()
{ 
      set("short", "����̨");
      set("long", HIG @LONG 
���￴��ȥ����һ�����䳡��ʮ�ɼ����ĳ����������������
��һȦ��ɫ���ʯ�������������Ƶ��ĸ��޴����ͭ������������
�仹�������ɵ�Ƥ��֯��̺���ڳ�����һ������Ƶİ���(shelf)��
�����Ա߻���һ�ž(note)��
LONG);
   set("exits",([
           "south" : __DIR__"xiuxishi",
]));
  set("objects",([
//             "/d/quest/tulong/npc/shadow" : 1,
  ]));
  set("item_desc", ([
     "shelf" : "����һ��ҩ�ܣ��������һЩ��ҩ���ƺ������ó���(take jinchuang)��\n", 
      "note" : "�¸ҵ��˰���������ǵĽŲ�����Ϊֹ���ͻ�ȥ�����(back)��\n", 
  ]));
//  set("no_clean_up", 0);
  setup();
}

void init()
{
        add_action("do_take", "take");
        add_action("do_back", "back");
        add_action("do_quit","hit");
        add_action("do_quit","kill");
        add_action("do_steal","steal");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"������ֻ��fight��\n");
        return 1;
}

int do_steal(string arg)
{
        write(this_player()->query("name")+"����ҪΪ�˲���֮�£�\n");
        return 1;
}
int do_take(string arg)
{      
        object me=this_player();
        object ob;
        if(!arg || arg!="jinchuang")
                return notify_fail("��Ҫ��ʲô��\n");
        if( !me->query("fighter") )
                return notify_fail("�㻹û���������ҩ��\n"); 
        ob = new ("/d/obj/drug/jinchuang");   
        ob->move(me); 
        message_vision ("$N��̨������$n��\n",me,ob); 
        return 1;  
}

int do_back(object me)
{
        me=this_player();
        message_vision(HIC"$N����Ӱ��ʧ��һ���â�С�\n"NOR,me); 
        me->set("fighter",0);
        me->set_temp("m_success/����",0);  
        me->set_temp("m_success/��Ӱ",0);  
        me->set_temp("m_success/����",0);  
        me->move("/d/city/center");
        return 1;
}

int valid_leave(string dir)
{
              if((present("jinchuang yao", this_player())))
            return notify_fail("�벻Ҫ��������Ķ�����\n"); 
        if((present("budai", this_player())))
            return notify_fail("����²���������Ķ������ܴ���ȥ��лл��\n"); 
    return ::valid_leave();

 }

