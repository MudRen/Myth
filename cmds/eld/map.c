//Cracked by Roath
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);


int main(object me, string arg)
{
    string map,name,*pname,msg,name1,info,cmds;
    int i;
    if( !arg ) {
    msg = HIY"map ��ͼ����ָ��ʹ��˵����\n"NOR;
    msg += "������������������������������������������������������������������������\n";
    msg += "map ��ʾ�������ļ���  ��ɫ�����㵱ǰ���ڵ�����\n";
    msg += "map here ���ı��ص�ͼ��\n";
    msg += "map main ������ͼ��\n";
//    msg += "map �������� ����ָ�������ĵ�ͼ��\n";
    msg += "������������������������������������������������������������������������\n";
    me->start_more(msg); 
    return 1; }
    if( arg == "main" ) {
       map = read_file("/doc/help/maps/map-all");
       me->start_more(map);
       return 1;  }
    if( arg == "here") { 
       name = environment(me)->query("outdoors");
       name = file_name(environment(me));
       pname = explode(name,"/");
       name =  pname[1];
    switch (name) 
     {
    case "city" :map = read_file("/doc/help/maps/map-changan");break;
    case "death":map = read_file("/doc/help/maps/map-hell");break;
    case "eastway":map = read_file("/doc/help/maps/map-changan-east");break;
    case "gao"  :map = read_file("/doc/help/maps/map-gao");break;
    case "huanggong":map = read_file("/doc/maps/help/map-huanggong");break;
//    case "jjf"  :map = read_file("/doc/maps/help/map-jjf");break;
    case "kaifeng" :map = read_file("/doc/maps/help/map-kaifeng");break;
    case "lingtai" :map = read_file("/doc/maps/help/map-fangcun");break;
    case "moon"    :map = read_file("/doc/maps/help/map-moon");break;
    case "nanhai"  :map = read_file("/doc/maps/help/map-putuo");break;
    case "pantao"  :map = read_file("/doc/maps/help/map-pantaohui");break;
//    case "penglai" :map = read_file("/doc/help/maps/map-penglai");break;
    case "qujing"  :{
               if (pname[2]=="wuzhuang") map = read_file("/doc/help/maps/map-wzg");

               else map = read_file("/doc/help/maps/map-"+pname[2]);break;
                    }
    case "westway" :map = read_file("/doc/help/maps/map-changan-west");break;
    case "xueshan" :map = read_file("/doc/help/maps/map-xueshan");break;
    case "sea"     :map = read_file("/doc/help/maps/map-longgong");break;
    case "dntg"    :
                 {
                   switch(pname[2]){
                       case "sky":map = read_file("/doc/help/maps/map-sky");break;
                       case "hgs":map = read_file("/doc/help/maps/map-aolai");break;
                            case "yunlou":map = read_file("/doc/help/maps/map-sky");break;
                       }
                    break;
                 }


    }
         
       
       if( map ) 
      {
       name1 = environment(me)->query("short");
       map = replace_string(map, name1, BGRN+HIR+name1+NOR);
 
       }
     else return notify_fail("Ŀǰ��վ��δ�ṩ�˵�ͼ��\n");
       me->start_more(map);
   }
    else return notify_fail("���뿴����ĵ�ͼ��\n");
    return 1;
}

