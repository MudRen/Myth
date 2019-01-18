// ְҵ���� ��ҽʦ��
// created by kuku@sjsh 2003.2

#include <ansi.h>
inherit ROOM;

string *drug1=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao"});
string *drug2=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing"});
string *drug3=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing","/d/quest/occupation/medical/obj/zhuguo","/d/quest/occupation/medical/obj/bingshen","/d/quest/occupation/medical/obj/tianxinshi","/d/quest/occupation/medical/obj/moguihua","/d/quest/occupation/medical/obj/huangxianlu","/d/quest/occupation/medical/obj/qxuelian"});
string *drug4=({"/d/quest/occupation/medical/obj/xiongh","/d/quest/occupation/medical/obj/jinshalan","/d/quest/occupation/medical/obj/yanwangteng","/d/quest/occupation/medical/obj/tongtiancao","/d/quest/occupation/medical/obj/yuanhancao","/d/quest/occupation/medical/obj/lingzhi","/d/quest/occupation/medical/obj/wujinggen","/d/quest/occupation/medical/obj/yinguo","/d/quest/occupation/medical/obj/heshouwu","/d/quest/occupation/medical/obj/kongqing","/d/quest/occupation/medical/obj/zhuguo","/d/quest/occupation/medical/obj/bingshen","/d/quest/occupation/medical/obj/tianxinshi","/d/quest/occupation/medical/obj/moguihua","/d/quest/occupation/medical/obj/huangxianlu","/d/quest/occupation/medical/obj/qxuelian","/d/quest/occupation/medical/obj/roufo","/d/quest/occupation/medical/obj/xdan","/d/quest/occupation/medical/obj/zizhi","/d/quest/occupation/medical/obj/moligen","/d/quest/occupation/medical/obj/changguo","/d/quest/occupation/medical/obj/xianru"});

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����һ���������̵�ɽ�֣������ͱ��Ͽ��Կ���������಻֪����С
��(grass)������Щ�ݿ���ȥ����ͨ�����Ǿ�˵�����ҽʦ�Ƕ�����Щ
С��Ϊ���ԭ��������������ȥ��ǿ���ҩƷ��ԭ�ϡ�
LONG
        );

        set("exits", ([   
                "southdown" : "/d/qujing/xiaoxitian/lindao7",
                "northeast" : __DIR__"shenshan2",
        ]));
        set("objects", ([   
        ])); 
        set("no_fight",1);
        set("no_magic",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("�����ں�æ�������ڣ�\n");
        
        if( !arg || arg != "grass")
                return notify_fail("��Ҫ��ʲô��\n");
        
        if ((me->query("sen") < 30)){  
                tell_object(me,"��ľ����ܼ��У�\n");
                return 1;
        }
        else if ((me->query("kee") < 50 )){
                tell_object(me,"�������״̬̫�\n");
                return 1;
        }
        
        if(!me->query("occupation") || me->query("occupation") != "ҽʦ"){
                tell_object(me,"���ڸ�ʲô��\n");
                return 1;
        }
                
        if(me->query("combat_exp") < 500000){
                tell_object(me,"�����ѧ���鲻����\n");
                return 1;
        }

        message_vision(HIC"$N�Ӷ���ͷ��ʼ�ڵ�������������\n"NOR,me);
        me->add("sen",-20);
        me->add("kee",-30);
        me->start_busy(6);   
        call_out("wayao",5,me);
        me->stop_busy();
        return 1;
}

int wayao(object me)
{
        object ob;

        if (random(10)<7){
                message_vision(CYN"һ���ھ�֮��$NʲôҲû�ڵ���\n"NOR,me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 600 ){        //��ҽ��
                message_vision(HIG"$N�ڵ������˰��죬�����ڵ�һ�ź�ҩ�ݡ�\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug4[random(22)]);
                ob->move(me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 400 ){        //ҩ��ʦ
                message_vision(HIG"$N�ڵ������˰��죬�����ڵ�һ�Ų����ҩ�ݡ�\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug3[random(16)]);
                ob->move(me);
                return 1;
        }
        else if ((int)me->query_skill("medical",1) > 200 ){        //��ҽ
                message_vision(HIG"$N�ڵ������˰��죬�����ڵ�һ�Ż��㲻���ҩ�ݡ�\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug2[random(10)]);
                ob->move(me);
                return 1;
        }       
        else{                                                      //��������
                message_vision(HIG"$N�ڵ������˰��죬�����ڵ�һ��ҩ�ݡ�\n"NOR,me); 
                me->improve_skill("medical", 1+random(4));
                ob=new(drug1[random(4)]);
                ob->move(me);
                return 1;
        }      
        return 1;
}
