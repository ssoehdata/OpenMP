! Figure 4.3

! Static extent of a parallel region is trhe code that is lexically
!   within the parallel/end parallel directive.

! Dynamic extent of a parallel region includes not only in the static extent region
!   but also all the code in subprograms invoked either directly or indirectly
!   from within the parallel region. 

    program main 
!$omp parallel                          !
    call whoami                         ! static extent <----
!$omp end parallel                      !                    |
end                                     !                    |    

    subroutine whoami                   !                    |
    external omp_get_thread_num         !                    | Dynamic extent
    integer iam, omp_get_thread_num     !                    |
!$omp critical                          ! static extent      |
    print *, "Hello from", iam          !                    |
!$omp end critical                      !               <----
    return                              !
    end                                 !

