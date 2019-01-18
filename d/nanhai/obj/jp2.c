//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jingping.c ��ƿ 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
   set_name("��ƿ", ({"jingping", "bottle"}));
   set_weight(1000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "�Ϻ�����ʢˮ�ľ�ƿ��\n");
     set("unit", "��");
     set("value", 5000);
     set("max_liquid", 500);
   }

   // because a container can contain different liquid
   // we set it to contain wine at the beginning
   set("liquid", ([
     "type": "water",
     "name": "ʥˮ",
     "remaining": 10,
     "drunk_apply": 20,
   ]));
}
void init()
{
        add_action("do_pour","pour");
}

int do_pour(string arg)
{
        object ob = this_player();
        object where = environment();


        if( ! arg || arg != "water" )
                return notify_fail("��Ҫ��ʲô�Ӿ�ƿ�е�������\n");
        if( !environment(environment())->query("killed") )
                return notify_fail("�����ò��ž�ƿ��\n");                
        if( query("liquid/remaining") < 1 )
                return notify_fail("ƿ���е�ʥˮ�Ѿ����ȹ��ˡ�\n");

        if( environment(environment())->query("short") != "������" )
                return notify_fail("��������Լ�Ҫȥ����ģ�\n");

        message_vision("$N�Ѿ�ƿ�е�ˮ�����ĵ������ϣ��漣�����ˡ�\n",ob);
        message_vision("�˲ι������Ͼͷ�������ѿ��\n",ob);
        remove_call_out("reware");
        call_out("reward",3,ob);
        return 1;
}

void reward(object ob)
{
        int i;

        string name=ob->query("name");

        if( ob->query("obstacle/wuzhuang") == "done" )
                return;
        if(! ob->query("obstacle/village") )
                return;
        if( !ob->query_temp("kill_tree") )
                return;

  i = random(600);
  ob->add("obstacle/number",1);
  ob->set("obstacle/wuzhuang","done");
        ob->add("daoxing",i+8000);
  message("channel:chat",HIC"�����ġ���Ԫ����(Zhenyuan daxian)��"+name+"��ׯ�۾Ȼ��˲ι�����\n"NOR,users());
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+ob->query("name")+"��������ȡ��[1;37m�ھŹأ�\n"NOR,users());
  tell_object (ob,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  ob->save();
  ob->delete("kill_tree");
  destruct(this_object());
  return;

}
