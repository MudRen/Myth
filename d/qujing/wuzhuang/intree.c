//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/intree.c


inherit ROOM;
#include <ansi.h>
void kill(object ob);
void appear(object ob);

void create ()
{
   set ("short", "������");
   set ("long", @LONG

�����������˹����Ķ��ϣ��˲ι���������ҡ�ڲ��������˲ι�
��ǧ��һ��������ǧ��һ���������ǧ��ŵ��죬��ͷһ����ſ�
�ԣ��ǹ��ӵ�ģ�����ͺ�����δ����С�����ƣ���֫��ȫ����پ�
ȫ��

LONG);

   set("exits", 
   ([ //sizeof() == 4
        "down": __DIR__"shugan3",
   ]));
   setup();
}
void init()
{
        add_action("do_hit","hit");
}

int do_hit()
{
        object ob = this_player();
        object wield,guo,guo1,guo2;
        object where = this_object();
       
       if( ob->is_busy() )
		return notify_fail("��������æ���ء�\n");
        if( where->query("killed")||
              ob->query_temp("kill_tree") )
                return notify_fail("������Ѿ���ή�ˡ�\n");
                
        if(!wield=ob->query_temp("weapon"))
                return notify_fail("��Ӧ���Ҹ����������˲ι���\n");
        
        if( wield->query("id") != "jinji zi"||
           ob->query("obstacle/wzg") == "done" )
           {
           message_vision(HIC"ֻ��$N��������"+wield->query("name")+"�������˲ι���ȥ��\n",ob);
           message_vision(HIC"�˲ι�ֻ�ǹ�µһ�����굽���²����ˡ�\n",ob);
           return 1;
            }
        
         else  
                if( ! ob->query_temp("prepared") )
                   {
           message_vision(HIC"ֻ��$N��������"+wield->query("name")+"�������˲ι���ȥ��\n",ob);
           message_vision(HIC"�˲ι�ֻ�ǹ�µһ�����굽���²����ˡ�\n",ob);
           return 1;
                  }
                if ( ob->query("obstacle/wzg") == "done"||
                    !ob->query("obstacle/village") )
                  {
                message_vision(HIC"ֻ��$N��������"+wield->query("name")+"���������ϵ��˲ι���ȥ��\n",ob);
                message_vision(HIC"һ���˲ι�ƮȻ������$N���������档\n"NOR,ob);
             guo2=new("/d/obj/drug/renshenguo-fake");
                guo2->move(ob);
                return 1;
                  }
                
  message_vision(HIC"ֻ��$N��������"+wield->query("name")+"���������ϵĹ�����ȥ��\n"NOR,ob);
  message_vision(HIC"һ���˲ι�ƮȻ������$N���������档\n"NOR,ob);
  remove_call_out("kill");
  remove_call_out("appear");
  call_out("kill",5,ob);
  call_out("appear",2,ob);
           guo=new("/d/obj/drug/renshenguo-fake");
  guo->move(ob);
  ob->start_busy(10);
  return 1;  
}
void appear(object ob)
{
        object where=this_object();

        object a = new("/d/qujing/wuzhuang/npc/mingyue");
        object b = new("/d/qujing/wuzhuang/npc/qingfeng");

        a->move(where);
        b->move(where);

        message_vision(HIW"\n��Ȼ��硢���´��˽�����\n",ob);
        message_vision(HIG"����ƿڴ��$N,����쵰��͵������ׯ�۵��˲ι���\n",ob);
        message_vision(HIG"�����ƿڴ��$N,���������\n",ob);
        message_vision(HIG"����ƿڴ��$N,��������ӣ�һ���˶����������������������ˡ�\n",ob);
        message_vision(HIG"�����ƿڴ��$N,����˲ι��Ӷ���������³�����\n",ob);
        message_vision(HIG"����ƿڴ��$N,���ǲ���ƽʱҲ��͵�������Ļ�ɫ��\n",ob);
        message_vision(HIG"�����ƿڴ��$N,�ҿ�����һ�������ͷ��\n",ob);
        message_vision(HIG"����ƿڴ��$N,��һ�����ú�����\n",ob);
        message_vision(HIG"�����ƿڴ��$N,����ģ�������Ӳ������ˡ�\n",ob);

}
void kill(object ob)
{
        object wield=ob->query_temp("weapon");
        object where = this_object();
        object a = find_living("qing feng");
        object b = find_living("ming yue");

        message_vision(HIC"ֻ��$N��������ͨ�죬���Ǹ�ŭ����ڡ�\n",ob);
        message_vision(HIC"$N�������е�"+wield->query("name")+"�����˲ι���������������ȥ��\n"NOR,ob);
        message_vision(HIC"����һ��ǰ����������������Ŀ�ή�ˡ�\n"NOR,ob);
        message("channel:chat",HIC"�����ġ�����(Ming yue)�������ˣ�"+ob->query("name")+"���˲ι����ҵ��ˡ�\n"NOR,users());
        tell_object(ob,"���£�����Ҳ�Ƶ������ˡ�\n");
        destruct(a);
        destruct(b);
        where->set("killed",1);
         ob->set_temp("kill_tree",1);
        return ;
}
