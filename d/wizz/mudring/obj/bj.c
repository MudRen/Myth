
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "������" NOR, ({ "bingqu jia", "jia" }) );         
        set_weight(30000000);
        set_max_encumbrance(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������Ÿ��ֱ����ļ��ӣ��\n");
        set("value", 1000000);
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("�����ʽ: get <��������> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: get <��������> from jia��\n");
    switch (arg1){
            case "changjian":
                ob=new("/clone/weapon/changjian");
                ob->move(me);
                break;   
            case "jian":
                ob=new("/clone/weapon/changjian");
                ob->move(me);
                break;   
           case "blade":
                ob=new("/clone/weapon/blade");
                ob->move(me);
                break; 
           case "gangdao":
                ob=new("/clone/weapon/blade");
                ob->move(me);
                break; 
  
          case "whip":
                ob=new("/clone/weapon/whip");
                ob->move(me);
                 break;
          case "changbian":
                ob=new("/clone/weapon/whip");
                ob->move(me);
                break;
         
         case  "tieling":
                ob=new("/clone/weapon/tieling");
                ob->move(me);
                break;
          case  "gangzhang":   
                ob=new("/clone/weapon/gangzhang");
                ob->move(me);
                 break;
          case  "staff":   
                ob=new("/clone/weapon/gangzhang");
                ob->move(me);
                 break;
          case  "zhen":
                ob=new("/clone/weapon/xiuhua");
                ob->move(me);
                break;
          case  "tiegun":
                 ob=new("clone/weapon/tiegun");
                 ob->move(me);
                 break;
          case  "club":
                 ob=new("clone/weapon/tiegun");
                 ob->move(me);
                 break;
           
         case  "hammer":
                ob=new("clone/weapon/tiechui");
                ob->move(me);
                break;
          case  "bang":
                 ob=new("clone/weapon/zhubang");
                 ob->move(me); 
                 break; 
          case  "armor":
                ob=new("clone/armor/armor");
                ob->move(me);
                 break;
          case  "tiejia":
                ob=new("clone/armor/armor");
                ob->move(me);
                 break;
          default :
                 return notify_fail("û�����ֱ�����\n");
                    }
       tell_room(environment(me), me->query("name")+"�ӱ�����������һ��"+ob->query("name")+"��\n", ({me}));         
       write("������һ��"+ob->query("name")+"��\n");
//     message_vision((string)me->query("name")+"�ӱ�����������һ��"+ob->query("name")+"��\n",me);  
       return 1;
}  

