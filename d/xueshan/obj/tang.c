inherit ITEM;

#include <ansi.h>


int do_he(string);

void create() 
  {
   set_name(YEL "������" NOR,({"tang"}));
   set("long","һ�뻨�����̵�"+this_object()->query("name")+"������(he)ζ����\n");
   set_weight(50);
   set("unit","��");
   setup();
  }

void init()
{
  add_action("do_he", "he");
}

int do_he(string arg)
  {
   object me=this_object();
   object who=this_player();
   if( !this_object()->id(arg) ) return notify_fail("�����ɶ��\n");
   message_vision("$N����"+me->query("name")+"��ཹ�ཱུĺ�����ȥ��\n", who);
   if ( me->query("prices")<= 0 )  message_vision("��ʲô��ζҲû��������\n", who);
   else if ( (int)who->query_skill("ningxie-force", 1) < 10 )  
     {
      message_vision("$Nֻ�е�һ����ģ�������ת��\n", who);
      who->unconcious();
     }
   else 
     {
      message_vision("$N������������ǿ����û�³�����\n", who);
      who->improve_skill("ningxie-force", me->query("prices"));
      tell_object(who,"��ֻ�е�����������ʮ��С���������Ҵ̣���ʹ����������"
         +"�Ž�������ҩ����ȫ���⡣\n");
      tell_object(who, YEL "��ı�����Ѫ��������"
         +chinese_number(me->query("prices"))+"�㣡\n" NOR);
     } 
   destruct(me);
   return 1;
  }

