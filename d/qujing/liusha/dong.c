//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�ڶ�");
  set ("long", @LONG

ˮ�����������ױȵ��ٶ�й��׶ˣ�ˮ������й�����˾޴����������
��ֵ��ǣ����е��м侹Ȼ����һ��ʯ����ˮ������ʯ����ת������
����й������������ʯ�������й���类�����ˡ�й���������
�ף�����㲻ƴ����[1;35mout[m���Ļ����������Ͼ�Ҫ�������ĵ����ˣ���

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/qujing/liusha/hedi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"ֻ��$N�ֽŲ��ã�������ʹ������������ʯ����������\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N���Լ��������Ѿ�����ס���е������ˣ�$N���󿴼����Ե�����С�����������֡�\n",ob);
        message_vision("����$N���һ˿�����ĺľ���$N������Ϳ�Ҫ���ڰ���û�ˣ�����\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

