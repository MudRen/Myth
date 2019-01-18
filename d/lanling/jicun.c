// ������ by Calvin


#include <ansi.h>
inherit ROOM;

object treasure_box;
object findbox();
void create ()
{
  object box;
  set ("short","����Ĵ���" );
  set ("long", @LONG
  
����һ�Ҵ��¼Ĵ���Ʒ�����ֺ�,�����϶�˵��ҵ��̵������ߣ�
���������Է��ĵİ���Ķ����Ĵ��ڴˣ����Ҽ۸񻹺ܹ�����
�����������Ĵ�(jicun)��Ʒ,�۸񹫵�,������Ʒ�����һ��
ÿСʱ����һ���������ڲ�ȡ(qu)����Ʒû�պ���ÿ������ʮ
���ĵͼ۹�������(pick box)��

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/calvin/lanling/jie3",
]));
  set("no_clean_up",1);
  set("no_magic",1);
  set("no_fight",1);
  
  set("objects",([
                   "/d/calvin/npc/jicuner" :1,
]));  

  
  setup();

    
}

object findbox()
{
  if(treasure_box && environment(treasure_box)==this_object()) 
    return treasure_box;
   treasure_box=new("/d/city/obj/shopbox");
  treasure_box->move(this_object());
  return treasure_box;  
}    

void init()
{
  add_action("do_jicun","jicun");
  add_action("do_qu","qu");
  add_action("do_pick","pick");
}

int do_jicun(string arg)
{
   object me=this_object();
   object who=this_player();
   object box;
   string box_mark;
   int limit;
   int deposit_time,value,afford;
   if (!treasure_box=findbox()) 
      return notify_fail("�Բ���,������ͣӪҵ!\n");
   if (!arg) return notify_fail("��Ҫ�Ĵ�ʲô����?\n");
   if (sscanf(arg,"%s for %d",arg,deposit_time)!=2) return notify_fail("��Ҫ�Ĵ�ʲô����?\n");
   box=present("deposit box",who);
   if (!box) return notify_fail("������û������������\n");
   if (deposit_time>120 || deposit_time<1 ||!intp(deposit_time)) 
      return notify_fail("���̼Ĵ��ʱ��ֻ����һ��һ�ٶ�ʮСʱ!\n");
   box_mark=box->query("mark");
   if (!box_mark || box_mark!=arg) return notify_fail("������û������������\n");
   limit=(int)who->query_temp("jicun_limit");
   if (limit && limit>4) return notify_fail("�Բ���,ÿ�������ֻ�ܼĴ�������ӡ�\n");
   if (mapp(treasure_box->query("goods/"+arg)))
      return notify_fail("�����Ѿ��Ĵ���ͬ����ǵ�������,�뻻������ټĴ档\n");
   value=deposit_time*100;
   if( !(afford=who->can_afford(value)) )  
     {
         write("��û���㹻��Ǯ��\n");
         return 1; 
     }   
   else if( afford == 2 )  
     {
         write("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
         return 1;
      }
   treasure_box->set("goods/"+arg+"/box",box);
   treasure_box->set("goods/"+arg+"/time",time()+deposit_time*3600);
   treasure_box->set("goods/"+arg+"/box_owner",who->query("id"));
   message_vision("$N�Ĵ�����һֻ������"
                +CHINESE_D->chinese_number(deposit_time)+"Сʱ��\n",who); 
   if (!treasure_box->query("goods/number")) treasure_box->set("goods/number",0);
   treasure_box->add("goods/number",1);
   box->move(treasure_box);
   who->start_busy(1);
   who->pay_money(value);
   who->add_temp("jicun_limit",1);
   return 1;
}

int do_qu(string arg)
{
   object box,me,who,deposit_box;
   mapping goods;
   string *goods_keys;
   int goods_number,i,flag=0;
   string box_owner;
   who=this_player();
   me=this_object();
   treasure_box=findbox();
   if (!treasure_box) return notify_fail("�Բ���,������ͣӪҵ!\n");
   if (!arg) return notify_fail("����ȡ��ʲô?\n");
   if (!treasure_box->query("goods/number")) return notify_fail("���̻�û���˼Ĵ��������\n");
   goods_keys=keys(treasure_box->query("goods"));
   goods_number=sizeof(goods_keys);
   if (goods_number<1) return notify_fail("���̻�û���˼Ĵ��������\n");
   for (i=0;i<goods_number;i++)
     {
       if (goods_keys[i]==arg) flag=1;
     }
   if (!flag) return notify_fail("����û���˼Ĵ���������!\n");
   box_owner=treasure_box->query("goods/"+arg+"/box_owner");
   if (box_owner!=who->query("id")) return notify_fail("��û�мĴ����������!\n");
   box=treasure_box->query("goods/"+arg+"/box");
   if (!box=present(box,treasure_box)) 
       return notify_fail("��Ĵ�Ķ����Ѿ���������,���������۵���!\n");   
   box->move(who);
   message_vision("$Nȡ��һ�����С�\n",who);
   who->add_temp("jicun_limit",-1);
   treasure_box->delete("goods/"+arg);
   treasure_box->add("goods/number",-1);    
   return 1;
}

int do_pick(string arg)
{
   object box,me,who,deposit_box;
   mapping goods;
   string *goods_keys,str;
   int goods_number,i,deposit_time,afford,value;
   who=this_player();
   me=this_object();
   if (!arg ||arg!="box") return 0;
   treasure_box=findbox();
   if (!treasure_box)
     return notify_fail("�Բ���,������ͣ����Ӫҵ!\n");
   if (!treasure_box->query("goods/number")) return notify_fail("������ʱ��û�п��Թ������۵���Ʒ��\n");
   goods_keys=keys(treasure_box->query("goods"));
   goods_number=sizeof(goods_keys);
   value=2000;
   if( !(afford=who->can_afford(value)) )  
      {
        write("��û���㹻��Ǯ��\n");
        return 1; 
      }   
   else if( afford == 2 )  
      {
        write("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
        return 1;
      }  
   for (i=0;i<goods_number;i++)
    {
      str=goods_keys[i];
      deposit_time=treasure_box->query("goods/"+str+"/time");
      if (deposit_time<time())
        {
          box=treasure_box->query("goods/"+str+"/box");
          if (str!="number" && box=present(box,treasure_box))
          {
            message_vision("$N����һֻ�����Ĵ����޵�����!\n",who);
            box->move(who);
            treasure_box->delete("goods/"+str);
            treasure_box->add("goods/number",-1);
            who->pay_money(value);
            return 1;
          } 
        }   
    }      
   message_vision("������ʱ��û�п��Թ������۵���Ʒ��\n",who);   
   return 1;  
}  
  
int clean_up()
{
      return 0;
}
  
